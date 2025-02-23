#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is Full! Cannot insert %d at front\n", value);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is Full! Cannot insert %d at rear\n", value);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty! Cannot delete from front\n");
        return;
    }
    printf("Deleted %d from front\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty! Cannot delete from rear\n");
        return;
    }
    printf("Deleted %d from rear\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty! No front element\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty! No rear element\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque Elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq = {{0}, -1, -1};

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 3);
    insertRear(&dq, 25);
    
    display(&dq);
    
    deleteFront(&dq);
    deleteRear(&dq);
    
    display(&dq);

    printf("Front Element: %d\n", getFront(&dq));
    printf("Rear Element: %d\n", getRear(&dq));

    return 0;
}
