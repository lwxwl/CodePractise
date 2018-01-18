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
    cout << "创建一棵树，其中A->Z代表树的数据，#表示空数" << endl;
    createBiTree(T);
    //ABD##E##CH###
    
    cout << "先序递归遍历： " << endl;
    preOrder(T);
    cout << endl;
    
    cout << "中序递归遍历：" << endl;
    inOrder(T);
    cout << endl;
    
    cout << "后序递归遍历：" << endl;
    postOrder(T);
    cout << endl;
    
    return 0;
}