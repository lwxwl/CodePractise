#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
using namespace std;

#define MAXLIST 100

struct sqList {
    int *list;
    int size;
    int num;
};

int *CreateList(sqList &L);
void DestroyList(sqList &L);
int ListSearch(sqList &L, int x);
int ListInsert(sqList &L, int pos, int x);
int ListDelete(sqList &L, int pos);
void ListTrave(sqList &L);

int *CreateList(sqList &L) {
    int i, n, x;
    L.list = (int *) malloc (MAXLIST * sizeof(int));
    if (!L.list) return NULL;
    L.size = MAXLIST;
    L.num = 0;
	cout << "input num of data: ";
    cin >> n;
    if (n > MAXLIST) return NULL;  

    for (i = 0; i < n; i++) {
		cout << "input data" << i+1 << ": ";
        cin >> x;
        L.list[i] = x;
        L.num++;
    }
}

void DestroyList(sqList &L) {
    if (L.list) free(L.list);
    L.num = L.size = 0;
}

int ListSearch(sqList &L, int x) {
    int i = 0;
    if (!L.num) return 0;
    while (1) {
        if (L.list[i] == x) return i+1;
        i++;
        if (i >= L.num) break;
    }
    return 0;
}

int ListInsert(sqList &L, int pos, int x) {
    int i;
    if (pos <= 0 || pos > L.num) return 0;
    if (L.num == L.size) return 0;  
    for (i = L.num-1; i >= pos-1; i--) {
        L.list[i+1] = L.list[i];      
    }
    L.list[pos-1] = x;
    L.num++;
}

int ListDelete(sqList &L, int pos) {
    int i;
    if (L.num == 0) return 0;
    if (pos <= 0 || pos > L.num) return 0;
    for (i = pos; i <= L.num-1; i++) {
        L.list[i-1] = L.list[i];     
    }
    L.num--;

}
void ListTrave(sqList &L) {
    int i;
    for (i = 0; i < L.num; i++) {
		cout << L.list[i] << " ";
    }
    cout << endl;
}

int main() {
    struct sqList L;
    CreateList(L);
    ListSearch(L, 4);
    ListTrave(L);
    ListInsert(L, 3, 10);
    ListTrave(L);
    ListDelete(L, 4);
    ListTrave(L);
    DestroyList(L);
}

