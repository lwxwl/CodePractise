#include "stdafx.h"
#include <iostream>
#define MaxVertexNum 100
#define QueueSize 30
using namespace std;

typedef enum{FALSE,TRUE}Boolean;
Boolean visited[MaxVertexNum];

typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];
    int n,e;
} MGraph;

void CreateMGraph(MGraph *G) {
    int i, j, k;
    char ch1, ch2;
	cout << "(顶点, 边数): " << endl;
    scanf("%d, %d", &(G->n), &(G->e));
	cout << "请依次输入顶点信息: " << endl;
    for (i = 0; i < G->n; i++) {
        getchar();
        scanf("%c", &(G->vexs[i]));
    }
    for (i = 0; i < G->n; i++) {
        for (j = 0; j < G->n; j++) {
            G->edges[i][j] = 0;
        }
    }
	cout << "请输入每条边对应的两个顶点的序号(i,j): " << endl;
    for (k = 0; k < G->e; k++) {
        getchar();
		cout << "请输入第" << k+1 << "条边的顶点序号：";
        scanf("%c, %c", &ch1, &ch2);
        for (i = 0; ch1 != G->vexs[i]; i++);
        for (j = 0; ch2 != G->vexs[j]; j++);
        G->edges[i][j] = 1;
    }
}

void DFSM(MGraph *G,int i) {
    int j;
	cout << "深度优先遍历结点：结点" << G->vexs[i] << endl;
    visited[i] = TRUE;
    for (j = 0; j < G->n; j++) {
        if (G->edges[i][j] == 1 && !visited[j]) {
            DFSM(G, j);
        }
    }
}

void DFSTraverseM(MGraph *G) {
    int i;
    for (i = 0; i < G->n; i++) {
        visited[i] = FALSE;
    }
    for (i = 0; i < G->n; i++) {
        if (!visited[i]) {
            DFSM(G, i);
        }
    }
}

typedef struct {
    int front;
    int rear;
    int count;
    int data[QueueSize];
} CirQueue;

void InitQueue(CirQueue *Q) {
    Q->front = Q->rear=0;
    Q->count = 0;
}

int QueueEmpty(CirQueue *Q) {
    return Q->count = QueueSize;
}

int QueueFull(CirQueue *Q) {
    return Q->count == QueueSize;
}

void EnQueue(CirQueue *Q, int x) {
    if (QueueFull(Q)) {
		cout << "Queue overflow" << endl;
    } else {
        Q->count++;
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % QueueSize;
    }
}

int DeQueue(CirQueue *Q) {
    int temp;
    if (QueueEmpty(Q)) {
		cout << "Queue underflow" << endl;
        return NULL;
    } else {
        temp = Q->data[Q->front];
        Q->count--;
        Q->front = (Q->front + 1) % QueueSize;
        return temp;
    }
}

void BFSM(MGraph *G,int k) {
    int i, j;
    CirQueue Q;
    InitQueue(&Q);
	cout << "广度优先遍历结点: 结点" << G->vexs[k] << endl;
    visited[k] = TRUE;
    EnQueue(&Q,k);
    while (!QueueEmpty(&Q)) {
        i = DeQueue(&Q);
        for (j = 0; j < G->n; j++) {
            if (G->edges[i][j] == 1 && !visited[j]) {
                cout << "广度优先遍历结点:" << G->vexs[j] << endl;
                visited[j] = TRUE;
                EnQueue(&Q, j);
            }
        }
    }
}

void BFSTraverseM(MGraph *G) {
    int i;
    for (i = 0; i < G->n; i++) {
        visited[i] = FALSE;
    }
    for (i = 0; i < G->n; i++) {
        if (!visited[i]) {
            BFSM(G, i);
        }
    }
}

int main() {
    MGraph G;
    CreateMGraph(&G);
    DFSTraverseM(&G);
    BFSTraverseM(&G);
    return 0;
}  

