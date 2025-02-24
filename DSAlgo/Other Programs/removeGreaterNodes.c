#include <stdio.h>
#include <stdlib.h>

// Definition for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Recursive function to remove nodes where the next node has a greater value
struct Node* removeGreaterRight(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: return if list is empty or has only one node
    }

    // Recursively process the next node
    head->next = removeGreaterRight(head->next);

    // If the current node's value is smaller than the next node, remove the current node
    if (head->data < head->next->data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver function
int main() {
    struct Node* head = NULL;

    // Inserting nodes into the linked list
    insertNode(&head, 10);
    insertNode(&head, 12);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 5);
    insertNode(&head, 16);
    insertNode(&head, 25);
    insertNode(&head, 8);

    printf("Original List:\n");
    printList(head);

    // Removing nodes with greater values to their right
    head = removeGreaterRight(head);

    printf("Modified List:\n");
    printList(head);

    return 0;
}
