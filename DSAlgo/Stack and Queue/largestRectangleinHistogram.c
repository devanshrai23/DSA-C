#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        return;
    }
    stack->data[++stack->top] = value;
}

void pop(Stack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

int top(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

int largestRectangleArea(int heights[], int n) {
    if (n == 0) {
        return 0;
    }
    
    int l[n], r[n];
    Stack stack;
    stack.top = -1;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&stack) && heights[top(&stack)] >= heights[i]) {
            pop(&stack);
        }
        r[i] = isEmpty(&stack) ? n : top(&stack);
        push(&stack, i);
    }
    
    stack.top = -1;
    
    for (int i = 0; i < n; i++) {
        while (!isEmpty(&stack) && heights[top(&stack)] >= heights[i]) {
            pop(&stack);
        }
        l[i] = isEmpty(&stack) ? -1 : top(&stack);
        push(&stack, i);
    }
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = r[i] - l[i] - 1;
        int currArea = heights[i] * width;
        if (currArea > maxArea) {
            maxArea = currArea;
        }
    }
    
    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    printf("Max Area: %d\n", largestRectangleArea(heights, n));
    return 0;
}
