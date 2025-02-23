#include<stdio.h>
#include <stdlib.h>

// stack implementation using array
// #define MAX 100 

// typedef struct {
//     int arr[MAX];
//     int top;
// } Stack;

// void push(Stack* s, int val) {
//     if(s->top == MAX-1) {
//         printf("Stack Overflow!\n");
//         return;
//     }
//     s->arr[++s->top] = val;
//     printf("Pushed %d into stack\n", val);
// }

// int pop(Stack* s) {
//     if(s->top == -1) {
//         printf("Stack Underflow!\n");
//         return -1;
//     }
//     return s->arr[s->top--];
// }

// int top(Stack *s) {
//     if(s->top == -1) {
//         printf("Stack is Empty!\n");
//         return -1;
//     }
//     return s->arr[s->top];
// }

// void display(Stack *s) {
//     if (s->top == -1) {
//         printf("Stack is empty!\n");
//         return;
//     }
//     printf("Stack Elements : ");
//     for(int i=0;i<=s->top;i++) {
//         printf("%d ",s->arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     Stack s;
//     s.top = -1;

//     push(&s, 10);
//     push(&s, 20);
//     push(&s, 30);
//     display(&s);

//     printf("Popped element : %d\n",pop(&s));

//     printf("Top element : %d\n",top(&s));
//     printf("Size of stack : %d\n",s.top + 1);
//     return 0;
// }

//stack implementation using linked list
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// typedef struct Stack {
//     Node* top;
//     int size;
// } Stack;

// void initStack(Stack* s) {
//     s->top = NULL;
//     s->size = 0;
// }

// void push(Stack* s, int val) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (!newNode) {
//         printf("Heap Overflow\n");
//         return;
//     }
//     newNode->data = val;
//     newNode->next = s->top;
//     s->top = newNode;
//     s->size++;
// }

// int pop(Stack* s) {
//     if (s->size == 0) {
//         printf("The stack is empty!\n");
//         return -1;
//     }
//     Node* temp = s->top;
//     int poppedValue = temp->data;
//     s->top = s->top->next;
//     free(temp);
//     s->size--;
//     return poppedValue;
// }

// int display_Top(Stack* s) {
//     if (s->size == 0) {
//         printf("The stack is empty!\n");
//         return -1;
//     }
//     return s->top->data;
// }

// int size(Stack* s) {
//     return s->size;
// }

// void displayStack(Stack* s) {
//     if (s->size == 0) {
//         printf("The stack is empty!\n");
//         return;
//     }
//     Node* temp = s->top;
//     printf("Stack elements : ");
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     Stack s;
//     initStack(&s);

//     push(&s, 10);
//     push(&s, 20);
//     push(&s, 30);
//     push(&s, 40);

//     printf("Top element: %d\n", display_Top(&s));
//     printf("Stack size: %d\n", size(&s));

//     displayStack(&s);

//     printf("Popping: %d\n", pop(&s));
//     displayStack(&s);

//     printf("Top element after pop: %d\n", display_Top(&s));
//     printf("Stack size after pop: %d\n", size(&s));

//     return 0;
// }

//stack implementation using queue
#define MAX 100

typedef struct {
    int arr[MAX];
    int start, end, size;
} Queue;

void pushQueue(Queue* q, int val) {
    if (q->size == MAX) {
        printf("Space is full!\n");
        return;
    }
    if (q->size == 0) {
        q->start = q->end = 0;
    } else {
        q->end = (q->end + 1) % MAX;
    }
    q->arr[q->end] = val;
    q->size++;
}

int popQueue(Queue* q) {
    if (q->size == 0) {
        printf("The queue is empty!\n");
        return -1;
    }
    int poppedValue = q->arr[q->start];
    if (q->size == 1) {
        q->start = q->end = -1;
    } else {
        q->start = (q->start + 1) % MAX;
    }
    q->size--;
    return poppedValue;
}

int topQueue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->start];
}

int sizeQueue(Queue* q) {
    return q->size;
}

typedef struct {
    Queue q;
} Stack;

void pushStack(Stack* s, int val) {
    pushQueue(&s->q, val);
    for (int i = 0; i < s->q.size - 1; i++) {
        pushQueue(&s->q, popQueue(&s->q));
    }
}

int popStack(Stack* s) {
    return popQueue(&s->q);
}

int topStack(Stack* s) {
    return topQueue(&s->q);
}

int sizeStack(Stack* s) {
    return sizeQueue(&s->q);
}

int main() {
    Stack s = {{{0}, -1, -1, 0}};

    pushStack(&s, 1);
    pushStack(&s, 2);
    pushStack(&s, 3);

    printf("Top element: %d\n", topStack(&s));
    printf("Stack size: %d\n", sizeStack(&s));

    popStack(&s);
    printf("Top after pop: %d\n", topStack(&s));
    printf("Stack size after pop: %d\n", sizeStack(&s));

    pushStack(&s, 4);
    printf("Top after push: %d\n", topStack(&s));
    printf("Stack size after push: %d\n", sizeStack(&s));

    return 0;
}
