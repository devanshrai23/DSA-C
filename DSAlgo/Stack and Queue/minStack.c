#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
    int min;
} MinStack;

void push(MinStack* s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    if (s->top == -1) {
        s->min = val;
        s->arr[++(s->top)] = val;
    } else {
        if (val > s->min) {
            s->arr[++(s->top)] = val;
        } else {
            s->arr[++(s->top)] = 2 * val - s->min;
            s->min = val;
        }
    }
}

void pop(MinStack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    if (s->arr[s->top] < s->min) {
        s->min = 2 * s->min - s->arr[s->top];
    }
    s->top--;
}

int top(MinStack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    if (s->arr[s->top] < s->min) {
        return s->min;
    }
    return s->arr[s->top];
}

int getMin(MinStack* s) {
    if (s->top == -1) {
        printf("Stack is empty, no minimum value\n");
        return -1;
    }
    return s->min;
}

void display(MinStack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack : ");
    for (int i = 0; i<= s->top; i++) {
        if (s->arr[i] < s->min) {
            printf("%d ", s->min);
        } else {
            printf("%d ", s->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    MinStack s = {{0}, -1, INT_MAX};

    push(&s, 3);
    push(&s, 4);
    push(&s, 9);
    push(&s, 1);
    push(&s, 5);

    display(&s);
    printf("Minimum element: %d\n", getMin(&s));

    pop(&s);
    display(&s);
    printf("Minimum element: %d\n", getMin(&s));

    pop(&s);
    display(&s);
    printf("Minimum element: %d\n", getMin(&s));

    pop(&s);
    display(&s);
    printf("Minimum element: %d\n", getMin(&s));

    return 0;
}
