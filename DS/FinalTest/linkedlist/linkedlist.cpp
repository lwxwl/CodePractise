#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct List {
    struct Node *list;
    int num;
};

void CreateList(List &L);
void DestroyList(List &L);
int ListSearch(List &L, int x);
int ListInsert(List &L, int pos, int x);
int ListDelete(List &L, int pos);
void ListTrave(List &L);

void CreateList(List &L) {
    int i, n, x;
    struct Node *p;
    L.list = NULL;
    L.num = 0;

	cout << "input num of data: ";
	cin >> n;

    for (i = 0; i < n; i++) {
		cout << "input data%d: " << i+1;
        cin >> x;

        p = (struct Node *) malloc (sizeof(struct Node));
        p->data = x;
        p->next = NULL;

        p->next = L.list;
        L.list = p;

        L.num++;
    }
}

void DestroyList(List &L) {
    struct Node *p;
    while (L.list) {
        p = L.list;
        L.list = L.list->next;
        free(L.list);
    }
    L.num = 0;
}

int ListSearch(List &L, int x) {
    struct Node *p;
    int i = 0;
    if (!L.num) return 0;
    p = L.list;
    while (p) {
        if (p->data == x) {
			return i+1;
		}
        i++;
    }
    return 0;
}

int ListInsert(List &L, int pos, int x) {
    struct Node *p, *q;
    int i;
    if (pos <= 0 || pos > L.num) {
		return 0;
	}
    if (pos == 0) {
        p = (struct Node *) malloc(sizeof(struct Node));
        if (!p) return 0;
        p->data = x;
        p->next = L.list;
        L.list = p;
        L.num++;
        return 1;
    }
    p = L.list;
    for (i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    q = (struct Node *) malloc(sizeof(struct Node));
    if (!q) return 0;
    q->data = x;
    q->next = p->next;
    p->next = q;
    L.num++;
    return 1;
}

int ListDelete(List &L, int pos) {
    struct Node *p, *q;
    int i;
    if (pos <= 0 || pos > L.num) return 0;
    if (pos == 1) {
        q = L.list;
        L.list = L.list->next;
        free(q);
        L.num--;
        return 1;
    }

    p = L.list;
    for (i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    q = p->next;
    q->next = p->next;
    free(q);
    L.num--;
    return 1;

}
void ListTrave(List &L) {
    struct Node *p;
    p = L.list;
    while (p) {
		cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    struct List L;
    CreateList(L);
    ListSearch(L, 4);
    ListTrave(L);
    ListInsert(L, 3, 10);
    ListTrave(L);
    ListDelete(L, 4);
    ListTrave(L);
    DestroyList(L);
	return 0;
}
