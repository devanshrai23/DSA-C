#include <stdio.h>
#include <stdlib.h>

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

Node* reverseKNodes(Node* head, int K) {
    if (head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    int count = 0;

    // Reverse first K nodes
    while (current != NULL && count < K) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse next K nodes and connect
    if (next != NULL) {
        head->next = reverseKNodes(next, K);
    }

    // Return the new head after reversing
    return prev;
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
    int K = 3;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    insertNode(&head, 7);
    insertNode(&head, 8);
    insertNode(&head, 9);

    printf("Original List:\n");
    printList(head);

    head = reverseKNodes(head, K);

    printf("Reversed List in Groups of K:\n");
    printList(head);

    return 0;
}


//Not reversing the left ones
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// Node* createNode(int value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = value;
//     newNode->next = NULL;
//     return newNode;
// }

// void insertNode(Node** head, int value) {
//     Node* newNode = createNode(value);
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }

//     Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// Node* reverseKNodes(Node* head, int K) {
//     Node* temp = head;
//     int count = 0;

//     // Count the number of nodes in the list
//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }

//     // If remaining nodes < K, return the head as it is
//     if (count < K) {
//         return head;
//     }

//     Node* prev = NULL;
//     Node* current = head;
//     Node* next = NULL;
//     int nodesReversed = 0;

//     // Reverse first K nodes
//     while (current != NULL && nodesReversed < K) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//         nodesReversed++;
//     }

//     // If remaining nodes are less than K, do not reverse further
//     if (current != NULL) {
//         head->next = reverseKNodes(current, K);
//     } else {
//         head->next = current; // Connect last group as it is
//     }

//     // Return the new head
//     return prev;
// }

// void printList(Node* head) {
//     while (head != NULL) {
//         printf("%d -> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     Node* head = NULL;
//     int K = 3;

//     insertNode(&head, 1);
//     insertNode(&head, 2);
//     insertNode(&head, 3);
//     insertNode(&head, 4);
//     insertNode(&head, 5);
//     insertNode(&head, 6);
//     insertNode(&head, 7);
//     insertNode(&head, 8);
//     insertNode(&head, 9);
//     insertNode(&head, 10);

//     printf("Original List:\n");
//     printList(head);

//     head = reverseKNodes(head, K);

//     printf("Reversed List in Groups of K (Last group remains unchanged if < K):\n");
//     printList(head);

//     return 0;
// }

