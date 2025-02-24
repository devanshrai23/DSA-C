#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure for stack node
typedef struct Node {
    int value;
    int minValue; // Stores the minimum value at this point in the stack
    struct Node* next;
} Node;

// Function to create a new stack node
Node* createNode(int value, int minValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->minValue = minValue;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, int value) {
    if (*top == NULL) {
        *top = createNode(value, value);
    } else {
        int minValue = (value < (*top)->minValue) ? value : (*top)->minValue;
        Node* newNode = createNode(value, minValue);
        newNode->next = *top;
        *top = newNode;
    }
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *top;
    int poppedValue = temp->value;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Function to get the top element of the stack
int top(Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    return top->value;
}

// Function to get the minimum element in the stack
int getMin(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->minValue;
}

// Main function to test the Min Stack
int main() {
    Node* stack = NULL;

    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 10);

    printf("Popped: %d\n", pop(&stack));  // Should pop 10
    printf("Top Element: %d\n", top(stack)); // Should be 4
    printf("Minimum Element: %d\n", getMin(stack)); // Should be 3

    return 0;
}
