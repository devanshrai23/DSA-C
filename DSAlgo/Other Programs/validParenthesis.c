#include <stdio.h>
#include <stdlib.h>

// Node structure for stack (linked list)
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, char data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
char pop(Node** top) {
    if (*top == NULL) {
        return '\0'; // Return null character if stack is empty
    }
    Node* temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to check if two characters are matching pairs
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if a given expression has valid parentheses
int isValidParentheses(char* expr) {
    Node* stack = NULL; // Initialize an empty stack

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // Push opening brackets onto stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // If closing bracket, check if it matches the top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack)) {
                return 0; // Unmatched closing bracket
            }
            char topChar = pop(&stack);
            if (!isMatchingPair(topChar, ch)) {
                return 0; // Mismatched brackets
            }
        }
    }

    // If stack is empty, parentheses are valid
    return isEmpty(stack);
}

// Main function to test the program
int main() {
    char expr[100];

    printf("Enter a parenthesis expression: ");
    scanf("%s", expr);

    if (isValidParentheses(expr)) {
        printf("Valid Parentheses\n");
    } else {
        printf("Invalid Parentheses\n");
    }

    return 0;
}
