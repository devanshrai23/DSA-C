#include <stdio.h>
#include <stdlib.h>

//queue implementation using array
// #define MAX 100

// typedef struct {
//     int arr[MAX];
//     int start, end, size;
// } Queue;

// void push(Queue* q, int val) {
//     if (q->size == MAX) {
//         printf("Space is full!\n");
//         return;
//     }
//     if (q->size == 0) {
//         q->start = q->end = 0;
//     } else {
//         q->end = (q->end + 1) % MAX;
//     }
//     q->arr[q->end] = val;
//     q->size++;
// }

// int pop(Queue* q) {
//     if (q->size == 0) {
//         printf("The queue is empty!\n");
//         return -1;
//     }
//     int poppedValue = q->arr[q->start];
//     if (q->size == 1) {
//         q->start = q->end = -1;
//     } else {
//         q->start = (q->start + 1) % MAX;
//     }
//     q->size--;
//     return poppedValue;
// }

// int top(Queue* q) {
//     if (q->size == 0) {
//         printf("Queue is empty!\n");
//         return -1;
//     }
//     return q->arr[q->start];
// }

// int size(Queue* q) {
//     return q->size;
// }

// void displayQueue(Queue* q) {
//     if (q->size == 0) {
//         printf("Queue is empty!\n");
//         return;
//     }
//     printf("Queue elements: ");
//     for (int i = 0; i < q->size; i++) {
//         int index = (q->start + i) % MAX;
//         printf("%d ", q->arr[index]);
//     }
//     printf("\n");
// }

// int main() {
//     Queue q = {{0}, -1, -1, 0};

//     push(&q, 1);
//     push(&q, 2);
//     push(&q, 3);

//     printf("Front element: %d\n", top(&q));
//     printf("Queue size: %d\n", size(&q));

//     pop(&q);
//     displayQueue(&q);

//     push(&q, 4);
//     push(&q, 5);
//     displayQueue(&q);

//     printf("Front element after push: %d\n", top(&q));
//     printf("Queue size after push: %d\n", size(&q));

//     pop(&q);
//     displayQueue(&q);

//     return 0;
// }

//queue implementation using linked list
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// typedef struct {
//     Node* start;
//     Node* end;
//     int size;
// } Queue;

// void initialize(Queue* q) {
//     q->start = q->end = NULL;
//     q->size = 0;
// }

// void push(Queue* q, int val) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (!newNode) {
//         printf("Memory allocation failed!\n");
//         return;
//     }
//     newNode->data = val;
//     newNode->next = NULL;
    
//     if (q->start == NULL) {
//         q->start = q->end = newNode;
//     } else {
//         q->end->next = newNode;
//         q->end = newNode;
//     }
//     q->size++;
// }

// int pop(Queue* q) {
//     if (q->start == NULL) {
//         printf("The queue is empty!\n");
//         return -1;
//     }
//     int poppedValue = q->start->data;
//     Node* temp = q->start;
//     q->start = q->start->next;
//     free(temp);
//     q->size--;
//     if (q->start == NULL) {
//         q->end = NULL;
//     }
//     return poppedValue;
// }

// int top(Queue* q) {
//     if (q->size == 0) {
//         printf("The queue is empty!\n");
//         return -1;
//     }
//     return q->start->data;
// }

// int Size(Queue* q) {
//     return q->size;
// }

// void display(Queue* q) {
//     if (q->start == NULL) {
//         printf("The queue is empty!\n");
//         return;
//     }
//     Node* temp = q->start;
//     while (temp) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     Queue q;
//     initialize(&q);
    
//     push(&q, 10);
//     push(&q, 20);
//     push(&q, 30);
    
//     printf("Front element: %d\n", top(&q));
//     printf("Queue size: %d\n", Size(&q));
    
//     pop(&q);
//     pop(&q);
    
//     printf("Front element after pops: %d\n", top(&q));
//     printf("Queue size after pops: %d\n", Size(&q));
    
//     display(&q);
    
//     return 0;
// }

//queue implementation using stack
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void pushStack(Stack* s, int val) {
    if(s->top == MAX-1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
}

int popStack(Stack* s) {
    if(s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

int topStack(Stack *s) {
    if(s->top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

typedef struct {
    Stack s1, s2;
} Queue;

void pushQueue(Queue* q, int val) {
    pushStack(&q->s1, val);
}

int popQueue(Queue* q) {
    if(q->s1.top == -1 && q->s2.top == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if(q->s2.top == -1) {
        while(q->s1.top != -1) {
            pushStack(&q->s2, popStack(&q->s1));
        }
    }
    return popStack(&q->s2);
}

int frontQueue(Queue* q) {
    if(q->s1.top == -1 && q->s2.top == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if(q->s2.top == -1) {
        while(q->s1.top != -1) {
            pushStack(&q->s2, popStack(&q->s1));
        }
    }
    return topStack(&q->s2);
}

int sizeQueue(Queue* q) {
    return q->s1.top + 1 + q->s2.top + 1;
}

int main() {
    Queue q = {{{0}, -1}, {{0}, -1}};

    pushQueue(&q, 1);
    pushQueue(&q, 2);
    pushQueue(&q, 3);

    printf("Front element: %d\n", frontQueue(&q));
    printf("Queue size: %d\n", sizeQueue(&q));

    printf("Popped element: %d\n", popQueue(&q));
    printf("Front after pop: %d\n", frontQueue(&q));
    printf("Queue size after pop: %d\n", sizeQueue(&q));

    pushQueue(&q, 4);
    printf("Front after push: %d\n", frontQueue(&q));
    printf("Queue size after push: %d\n", sizeQueue(&q));

    return 0;
}

