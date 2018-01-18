#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct BiTNode{
    char data;
    struct BiTNode *leftChild;
    struct BiTNode *rightChild;
};

BiTNode *T;

void createBiTree(BiTNode* &T);
void inOrder(BiTNode* &T);
void preOrder(BiTNode* &T);
void postOrder(BiTNode* &T);

void createBiTree(BiTNode* &T) {
    char ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
    } else {
        T = new BiTNode;
        T->data = ch;
        createBiTree(T->leftChild);
        createBiTree(T->rightChild);
    }
}

void preOrder(BiTNode* &T) {
    if(T) {
        cout << T->data;
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    } else {
        cout << "";
    }
}

void inOrder(BiTNode* &T) {
    if(T) {
        inOrder(T->leftChild);
        cout << T->data;
        inOrder(T->rightChild);
    } else {
        cout << "";
    }
}

void postOrder(BiTNode* &T) {
    if(T) {
        postOrder(T->leftChild);
        postOrder(T->rightChild);
        cout << T->data;
    } else {
        cout << "";
    }
}

int main() {
    cout << "����һ����������A->Z�����������ݣ�#��ʾ����" << endl;
    createBiTree(T);
    //ABD##E##CH###
    
    cout << "����ݹ������ " << endl;
    preOrder(T);
    cout << endl;
    
    cout << "����ݹ������" << endl;
    inOrder(T);
    cout << endl;
    
    cout << "����ݹ������" << endl;
    postOrder(T);
    cout << endl;
    
    return 0;
}