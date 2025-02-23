#include<stdio.h>

typedef struct mlNode {
    int row, col, val;
    struct mlNode *nextRow, *nextCol;
} mlNode;

mlNode *above(mlNode* head, int r, int c) {         //returns above pointer
    mlNode* p = head, *q;
    while(p->col != c) {
        p = p->nextCol;
    }

    do {
        q = p;
        p = p->nextRow;
    } while(p->row !=r && p->row !=-1);

    return q;
}

mlNode *above(mlNode* head, int r, int c) {         //returns left pointer
    mlNode* p = head, *q;
    while(p->row != c) {
        p = p->nextRow;
    }

    do {
        q = p;
        p = p->nextCol;
    } while(p->col !=r && p->col !=-1);

    return q;
}

mlNode* insert(mlNode* head, int r, int c, int v) {
    mlNode* newNode = (mlNode*)malloc(sizeof(mlNode));
    mlNode* a, *l;
    newNode->row = r;
    newNode->col = c;
    newNode->val = v;

    a = above(head,r,c);
    l = left(head,r,c);
    newNode->nextRow = a->nextRow;
    a->nextRow = newNode;
    newNode->nextCol = a->nextCol;
    l->nextCol = newNode;
    return head;
}

void deletion(mlNode* head, int r, int c) {
    mlNode* a, *l, *p;
    a = above(head,r,c);
    l = left(head,r,c);
    p = a->nextRow;
    a->nextRow = p->newRow;
    l->nextCol = p->newCol;
    return head;
}