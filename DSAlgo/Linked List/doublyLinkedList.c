#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyList {
    Node* head;
    Node* tail;
} DoublyList;


void initialize(DoublyList* dll) {
    dll->head = dll->tail = NULL;
}

void push_front(DoublyList* dll, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dll->head;
    newNode->prev = NULL;
    if (dll->head != NULL)
        dll->head->prev = newNode;
    else
        dll->tail = newNode;
    dll->head = newNode;
}

void push_back(DoublyList* dll, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = dll->tail;
    newNode->next = NULL;
    if (dll->tail != NULL)
        dll->tail->next = newNode;
    else
        dll->head = newNode;
    dll->tail = newNode;
}

void insert_at_position(DoublyList* dll, int val, int pos) {
    if (pos == 1) {
        push_front(dll, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    Node* temp = dll->head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        push_back(dll, val);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void pop_front(DoublyList* dll) {
    if (dll->head == NULL) {
        printf("DLL is empty\n");
        return;
    }
    Node* temp = dll->head;
    dll->head = dll->head->next;
    if (dll->head != NULL)
        dll->head->prev = NULL;
    else
        dll->tail = NULL;
    free(temp);
}

void pop_back(DoublyList* dll) {
    if (dll->tail == NULL) {
        printf("DLL is empty\n");
        return;
    }
    Node* temp = dll->tail;
    dll->tail = dll->tail->prev;
    if (dll->tail != NULL)
        dll->tail->next = NULL;
    else
        dll->head = NULL;
    free(temp);
}

void delete_at_position(DoublyList* dll, int pos) {
    if (pos <= 1 || dll->head == NULL) {
        pop_front(dll);
        return;
    }
    Node* temp = dll->head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        pop_back(dll);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int count_nodes(DoublyList* dll) {
    int count = 0;
    Node* temp = dll->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printDLL(DoublyList* dll) {
    if (dll->head == NULL) {
        printf("DLL is Empty\n");
        return;
    }
    Node* temp = dll->head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void menu() {
    printf("\nDoubly Linked List Operations:\n");
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
    DoublyList dll;
    initialize(&dll);
    int choice, val, pos;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                push_front(&dll, val);
                break;
            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &val);
                push_back(&dll, val);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &val, &pos);
                insert_at_position(&dll, val, pos);
                break;
            case 4:
                pop_front(&dll);
                break;
            case 5:
                pop_back(&dll);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(&dll, pos);
                break;
            case 7:
                printf("Total nodes: %d\n", count_nodes(&dll));
                break;
            case 8:
                printDLL(&dll);
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
