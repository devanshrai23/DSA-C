#include <stdio.h>
#include <stdlib.h>

#define MAX 20  

struct TwoStacks {
    int arr[MAX];
    int top1;  
    int top2;
};

void push1(struct TwoStacks *ts, int value) {
    if (ts->top1 < ts->top2 - 1) {  
        ts->arr[++ts->top1] = value;
    } else {
        printf("Stack Overflow! No space for stack1\n");
    }
}

void push2(struct TwoStacks *ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = value;
    } else {
        printf("Stack Overflow! No space for stack2\n");
    }
}

int pop1(struct TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack Underflow! Stack1 is empty\n");
        return -1;
    }
}

int pop2(struct TwoStacks *ts) {
    if (ts->top2 < MAX) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack Underflow! Stack2 is empty\n");
        return -1;
    }
}

int topStack1(struct TwoStacks ts) {
    if (ts.top1 >= 0) {
        return ts.arr[ts.top1];
    } else {
        printf("Stack1 is empty\n");
        return -1;
    }
}

int topStack2(struct TwoStacks ts) {
    if (ts.top2 < MAX) {
        return ts.arr[ts.top2];
    } else {
        printf("Stack2 is empty\n");
        return -1;
    }
}

void displayStack1(struct TwoStacks ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts.top1; i++) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");
}

void displayStack2(struct TwoStacks ts) {
    printf("Stack2: ");
    for (int i = MAX - 1; i >= ts.top2; i--) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");
}

int main() {
    struct TwoStacks ts;
    
    ts.top1 = -1;      
    ts.top2 = MAX; 

    push1(&ts, 10);
    push1(&ts, 20);
    push1(&ts, 30);
    push2(&ts, 40);
    push2(&ts, 50);
    
    displayStack1(ts);
    displayStack2(ts);

    printf("Top of Stack1: %d\n", topStack1(ts));
    printf("Top of Stack2: %d\n", topStack2(ts));

    printf("Popped from Stack1: %d\n", pop1(&ts));
    printf("Popped from Stack2: %d\n", pop2(&ts));

    displayStack1(ts);
    displayStack2(ts);

    printf("Top of Stack1 after pop: %d\n", topStack1(ts));
    printf("Top of Stack2 after pop: %d\n", topStack2(ts));

    return 0;
}
