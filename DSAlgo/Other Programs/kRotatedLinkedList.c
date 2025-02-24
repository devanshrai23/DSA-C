#include <stdio.h>
#include <stdlib.h>

// Define a node structure using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* rotateClockwise(Node* head, int K) {
    if (head == NULL || head->next == NULL || K == 0) {
        return head;
    }

    // Step 1: Compute the length of the linked list
    Node* temp = head;
    int n = 1; // Start with 1 as we're already at head
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: Update K to avoid unnecessary rotations
    K = K % n;
    if (K == 0) {
        return head; // No rotation needed
    }

    // Step 3: Connect the last node to the head to form a circular list
    temp->next = head;

    // Step 4: Find the new tail (n-K-1 position from start)
    int stop = n - K - 1;
    temp = head;
    for (int i = 0; i < stop; i++) {
        temp = temp->next;
    }

    // Step 5: Set the new head and break the circular link
    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int K;
    printf("Enter the value of K : ");
    scanf("%d",&K); 

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);
    insertNode(&head, 60);

    printf("Original List:\n");
    printList(head);

    head = rotateClockwise(head, K);

    printf("Rotated List:\n");
    printList(head);

    return 0;
}
