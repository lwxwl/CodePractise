#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    struct Node *bottom;
};

struct Queue {
    struct Node *rear;
    struct Node *front;
};

void CreateStack(struct Stack &s);
void DestroyStack(struct Stack &s);
int Push(struct Stack &s, int x);
int Pop(struct Stack &s, int &x);
int GetStack(struct Stack &s, int &x);
int IsStackEmpty(struct Stack &s);
int IsStackFull(struct Stack &s);
void StackTraverse(Stack s);

void InitQueue(struct Queue &Q);
void DestroyQueue(struct Queue &Q);
int EnQueue(struct Queue &Q, int x);
int DeQueue(struct Queue &Q, int &x);
void QueueTraverse(Queue Q);
int QueueLength(struct Queue Q);

void CreateStack(struct Stack &s) {
    s.bottom = s.top = new struct Node;
    s.top->next = NULL;
}

void DestroyStack(struct Stack &s) {
    while (s.bottom) {
        s.bottom = s.top;
        s.top = s.top->next;
        delete s.bottom;
    }
}

int Push(struct Stack &s, int x) {
    struct Node *p;

    p = new struct Node;
    p->next = NULL;
    p->data = x;

    p->next = s.top->next;
    s.top->next = p;
	return 1;
}

int Pop(struct Stack &s, int &x) {
    struct Node *p;
    p = s.top->next;
    s.top->next = s.top->next->next;
    x = p->data;
    free(p);
    return x;
}

int GetStack(struct Stack &s, int &x) {
    if (s.top == s.bottom) return 0;
    x = s.top->next->data;
    return x;

}

int IsStackEmpty(struct Stack &s) {
    return s.top == s.bottom;
}

int IsStackFull(struct Stack &s) {
    return 1;
}

void StackTraverse(Stack s) {
	struct Node *p;
	p = s.top->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void InitQueue(struct Queue &Q) {
    Q.front = Q.rear = new struct Node;
    Q.front->next=NULL;
}

void DestroyQueue(struct Queue &Q) {
    while(Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

int EnQueue(struct Queue &Q, int x) {
    struct Node *p;
    if (!(p = (Node *) malloc (sizeof(Node)))) {
        exit(0);
    }
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
	return 1;
}

int DeQueue(struct Queue &Q, int &x) {
    struct Node *p;
    if (Q.front == Q.rear) {
        return false;
    }
    p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return x;
}

void QueueTraverse(Queue Q) {
    struct Node *p;
    p = Q.front->next;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool QueueEmpty(Queue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}

int QueueLength(struct Queue Q) {
    int i = 0;
    struct Node *p;
    p = Q.front;
    while(Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}


int main() {
    int x;
    struct Stack s;
	CreateStack(s);
	Push(s, 1);
	Push(s, 2);
	StackTraverse(s);
	Pop(s, x);
	cout << x << endl;
   
	struct Queue q;
	InitQueue(q);
	EnQueue(q, 1);
	EnQueue(q, 2);
	QueueTraverse(q);
	DeQueue(q, x);
	cout << x << endl;
	return 0;
}
