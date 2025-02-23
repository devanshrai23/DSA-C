#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyCircularList {
    Node* head;
} DCLL;

void initialize(DCLL* dcll) {
    dcll->head = NULL;
}

void push_front(DCLL* dcll, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (dcll->head == NULL) {
        newNode->next = newNode->prev = newNode;
        dcll->head = newNode;
    } else {
        Node* tail = dcll->head->prev;
        newNode->next = dcll->head;
        newNode->prev = tail;
        tail->next = newNode;
        dcll->head->prev = newNode;
        dcll->head = newNode;
    }
}

void push_back(DCLL* dcll, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (dcll->head == NULL) {
        newNode->next = newNode->prev = newNode;
        dcll->head = newNode;
    } else {
        Node* tail = dcll->head->prev;
        newNode->next = dcll->head;
        newNode->prev = tail;
        tail->next = newNode;
        dcll->head->prev = newNode;
    }
}

void insert_at_position(DCLL* dcll, int val, int pos) {
    if (pos == 1 || dcll->head == NULL) {
        push_front(dcll, val);
        return;
    }
    
    Node* temp = dcll->head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    for (int i = 1; i < pos - 1 && temp->next != dcll->head; i++) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void pop_front(DCLL* dcll) {
    if (dcll->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = dcll->head;
    Node* tail = dcll->head->prev;
    
    if (dcll->head->next == dcll->head) {
        dcll->head = NULL;
    } else {
        dcll->head = dcll->head->next;
        dcll->head->prev = tail;
        tail->next = dcll->head;
    }
    
    free(temp);
}

void pop_back(DCLL* dcll) {
    if (dcll->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* tail = dcll->head->prev;
    
    if (dcll->head->next == dcll->head) {
        dcll->head = NULL;
    } else {
        tail->prev->next = dcll->head;
        dcll->head->prev = tail->prev;
    }
    
    free(tail);
}

void delete_at_position(DCLL* dcll, int pos) {
    if (pos <= 1 || dcll->head == NULL) {
        pop_front(dcll);
        return;
    }
    
    Node* temp = dcll->head;
    
    for (int i = 1; i < pos && temp->next != dcll->head; i++) {
        temp = temp->next;
    }
    
    if (temp->next == dcll->head) {
        pop_back(dcll);
        return;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int count_nodes(DCLL* dcll) {
    if (dcll->head == NULL) return 0;
    
    int count = 0;
    Node* temp = dcll->head;
    
    do {
        count++;
        temp = temp->next;
    } while (temp != dcll->head);
    
    return count;
}

void printList(DCLL* dcll) {
    if (dcll->head == NULL) {
        printf("List is Empty\n");
        return;
    }
    
    Node* temp = dcll->head;
    
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != dcll->head);
    
    printf("(Back to Head)\n");
}

void menu() {
    printf("\nDoubly Circular Linked List Operations:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Back\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Front\n");
    printf("5. Delete from Back\n");
    printf("6. Delete from Position\n");
    printf("7. Count Nodes\n");
    printf("8. Print List\n");
    printf("9. Exit\n");
}

int main() {
    DCLL dcll;
    initialize(&dcll);
    int choice, val, pos;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                push_front(&dcll, val);
                break;
            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &val);
                push_back(&dcll, val);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &val, &pos);
                insert_at_position(&dcll, val, pos);
                break;
            case 4:
                pop_front(&dcll);
                break;
            case 5:
                pop_back(&dcll);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(&dcll, pos);
                break;
            case 7:
                printf("Total nodes: %d\n", count_nodes(&dcll));
                break;
            case 8:
                printList(&dcll);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 9);

    return 0;
}
