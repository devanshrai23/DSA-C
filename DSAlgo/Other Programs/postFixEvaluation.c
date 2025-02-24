#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define structure for stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

// Function to check if stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Error: Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Node* stack = NULL;
    char* token = strtok(expression, " "); // Tokenize the input based on space

    while (token != NULL) {
        if (isdigit(token[0])) {
            // If the token contains an underscore, remove it and convert to number
            char numberWithoutUnderscore[20];
            int j = 0;

            for (int i = 0; token[i] != '\0'; i++) {
                if (token[i] != '_') {
                    numberWithoutUnderscore[j++] = token[i];
                }
            }
            numberWithoutUnderscore[j] = '\0';

            // Convert to integer and push onto the stack
            push(&stack, atoi(numberWithoutUnderscore));
        } 
        else { // Token is an operator
            if (isEmpty(stack)) {
                printf("Error: Invalid expression\n");
                return -1;
            }

            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = 0;

            switch (token[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    result = operand1 / operand2; 
                    break;
                default: 
                    printf("Error: Invalid operator %c\n", token[0]);
                    return -1;
            }

            // Push result back onto the stack
            push(&stack, result);
        }

        token = strtok(NULL, " "); // Get next token
    }

    // Final result should be the only element in the stack
    if (stack == NULL || stack->next != NULL) {
        printf("Error: Invalid expression\n");
        return -1;
    }

    return pop(&stack);
}

// Main function
int main() {
    char expression1[] = "3 4 + 2 * 7 /";
    char expression2[] = "10_2 3 + 5 *";

    printf("Result of Expression 1: %d\n", evaluatePostfix(expression1));
    printf("Result of Expression 2: %d\n", evaluatePostfix(expression2));

    return 0;
}
