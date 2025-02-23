#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertAtHead(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
        return;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
}

void insertAtTail(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void insertAtPosition(int val, int pos) {
    if (pos == 1) {
        insertAtHead(val);
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    if (temp == tail) {
        tail = newNode;
    }
}

void deleteAtHead() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    else if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}

void deleteAtTail() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    else if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }
    
    Node* temp = tail;
    Node* prev = head;
    while (prev->next != tail) {
        prev = prev->next;
    }
    tail = prev;
    tail->next = head;
    free(temp);
}

void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteAtHead();
        return;
    }
    
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == tail) {
        deleteAtTail();
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

int countNodes() {
    if (head == NULL) return 0;
    
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printCLL() {
    if (head == NULL) {
        printf("CLL is Empty\n");
        return;
    }
    
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d\n", head->data);
}

int main() {
    int choice, val, pos;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Count Nodes\n");
        printf("8. Print List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtHead(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtTail(val);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPosition(val, pos);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 8:
                printCLL();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
