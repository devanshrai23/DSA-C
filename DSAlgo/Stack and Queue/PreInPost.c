#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char arr[MAX][MAX];
    int top;
} Stack;

void push(Stack* s, char* val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    strcpy(s->arr[++s->top], val);
}

char* pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return "";
    }
    return s->arr[s->top--];
}

int isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int priority(char ch) {
    if (ch == '-' || ch == '+')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void replaceParentheses(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1;
    int j = 0;
    
    for (int i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, &infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.arr[s.top][0] != '(') {
                postfix[j++] = pop(&s)[0];
            }
            pop(&s);
        } else {
            while (s.top != -1 && priority(infix[i]) <= priority(s.arr[s.top][0])) {
                postfix[j++] = pop(&s)[0];
            }
            push(&s, &infix[i]);
        }
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s)[0];
    }
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);
    replaceParentheses(infix);
    infixToPostfix(infix, prefix);
    reverseString(prefix);
}

void postfixToInfix(char* postfix, char* infix) {
    Stack s;
    s.top = -1;
    char temp[MAX];
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        if (isalpha(ch) || isdigit(ch)) {
            char str[2] = {ch, '\0'};
            push(&s, str);
        } else {
            char t1[MAX], t2[MAX];
            strcpy(t1, pop(&s));
            strcpy(t2, pop(&s));
            sprintf(temp, "(%s%c%s)", t2, ch, t1);
            push(&s, temp);
        }
    }
    strcpy(infix, pop(&s));
}

void prefixToInfix(char* prefix, char* infix) {
    reverseString(prefix);
    postfixToInfix(prefix, infix);
    reverseString(infix);
}

void postfixToPrefix(char* postfix, char* prefix) {
    Stack s;
    s.top = -1;
    char temp[MAX];
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        if (isalpha(ch) || isdigit(ch)) {
            char str[2] = {ch, '\0'};
            push(&s, str);
        } else {
            char t1[MAX], t2[MAX];
            strcpy(t1, pop(&s));
            strcpy(t2, pop(&s));
            sprintf(temp, "%c%s%s", ch, t2, t1);
            push(&s, temp);
        }
    }
    strcpy(prefix, pop(&s));
}

void prefixToPostfix(char* prefix, char* postfix) {
    reverseString(prefix);
    postfixToPrefix(prefix, postfix);
    reverseString(postfix);
}

int main() {
    int choice;
    char expression[MAX], result[MAX];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Prefix to Infix\n");
        printf("5. Postfix to Prefix\n");
        printf("6. Prefix to Postfix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 7) break;

        printf("Enter the expression: ");
        fgets(expression, MAX, stdin);
        expression[strcspn(expression, "\n")] = 0;
        
        switch (choice) {
            case 1:
                infixToPostfix(expression, result);
                break;
            case 2:
                infixToPrefix(expression, result);
                break;
            case 3:
                postfixToInfix(expression, result);
                break;
            case 4:
                prefixToInfix(expression, result);
                break;
            case 5:
                postfixToPrefix(expression, result);
                break;
            case 6:
                prefixToPostfix(expression, result);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        printf("Result: %s\n", result);
    }
    return 0;
}
