#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_atStart(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

Node* insert_atEnd(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* delete_atStart(Node* head) {
    if (head == NULL) {
        printf("The list is already empty!\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delete_atEnd(Node* head) {
    if (head == NULL) {
        printf("The list is already empty!\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

Node* insert_atPos(Node* head, int val, int pos) {
    if (pos < 0) {
        printf("Invalid Position!\n");
        return head;
    }
    if (pos == 0) {
        return insert_atStart(head, val);
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bound!\n");
            return head;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* delete_atPos(Node* head, int position) {
    if (head == NULL || position < 0) {
        return head;
    }
    if (position == 0) {
        return delete_atStart(head);
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

int length(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, pos;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node at the start\n");
        printf("4. Delete a Node at the end\n");
        printf("5. Insert at a position\n");
        printf("6. Delete at a position\n");
        printf("7. Display number of nodes\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter a value to be inserted: ");
            scanf("%d", &data);
            head = insert_atStart(head, data);
        } 
        else if (choice == 2) {
            printf("Enter a value to be inserted: ");
            scanf("%d", &data);
            head = insert_atEnd(head, data);
        } 
        else if (choice == 3) {
            head = delete_atStart(head);
        } 
        else if (choice == 4) {
            head = delete_atEnd(head);
        } 
        else if (choice == 5) {
            printf("Enter a value to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            head = insert_atPos(head, data, pos);
        } 
        else if (choice == 6) {
            printf("Enter the position: ");
            scanf("%d", &pos);
            head = delete_atPos(head, pos);
        } 
        else if (choice == 7) {
            printf("Number of Nodes: %d\n", length(head));
        } 
        else if (choice == 8) {
            displayList(head);
        } 
        else if (choice == 9) {
            exit(0);
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }        
    }
    return 0;
}
