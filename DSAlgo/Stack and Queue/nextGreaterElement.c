#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack* s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

int top(Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[s->top];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void nextGreaterElement(int arr[], int n, int ans[]) {
    Stack s;
    s.top = -1;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&s) && top(&s) <= arr[i]) {
            pop(&s);
        }
        ans[i] = isEmpty(&s) ? -1 : top(&s);
        push(&s, arr[i]);
    }
}

int main() {
    int arr[] = {6, 8, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];

    nextGreaterElement(arr, n, ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
