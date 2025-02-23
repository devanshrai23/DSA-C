#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row, col, val;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int row, int col, int val) {
    Node* newNode = createNode(row, col, val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL) {
        printf("Sparse Matrix is empty!\n");
        return;
    }
    
    printf("\nSparse Matrix (Row, Column, Value):\n");
    printf("-----------------------------------\n");
    printf("Row\tCol\tValue\n");
    
    Node* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
}

void deleteNode(Node** head, int row, int col) {
    if (*head == NULL) {
        printf("Sparse Matrix is empty!\n");
        return;
    }

    Node *temp = *head, *prev = NULL;

    while (temp != NULL && (temp->row != row || temp->col != col)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found!\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Element at (%d, %d) deleted successfully!\n", row, col);
}

void deleteRow(Node** head, int delRow) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->row == delRow) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Row %d deleted successfully!\n", delRow);
}

void deleteColumn(Node** head, int delCol) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->col == delCol) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Column %d deleted successfully!\n", delCol);
}

void insertRow(Node** head, int newRow, int defaultValue) {
    Node* temp = *head;
    
    while (temp != NULL) {
        if (temp->row >= newRow) {
            temp->row++;
        }
        temp = temp->next;
    }

    if (defaultValue != 0) {
        insert(head, newRow, 0, defaultValue);
    }
    
    printf("Row %d inserted successfully!\n", newRow);
}

void insertColumn(Node** head, int newCol, int defaultValue) {
    Node* temp = *head;
    
    while (temp != NULL) {
        if (temp->col >= newCol) {
            temp->col++;
        }
        temp = temp->next;
    }

    if (defaultValue != 0) {
        insert(head, 0, newCol, defaultValue);
    }
    
    printf("Column %d inserted successfully!\n", newCol);
}

int main() {
    Node* sparseMatrix = NULL;
    int choice, row, col, val;

    while (1) {
        printf("\nSparse Matrix Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Display Sparse Matrix\n");
        printf("3. Delete an Element\n");
        printf("4. Delete a Row\n");
        printf("5. Delete a Column\n");
        printf("6. Insert a Row\n");
        printf("7. Insert a Column\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter row, column, and value: ");
                scanf("%d %d %d", &row, &col, &val);
                insert(&sparseMatrix, row, col, val);
                break;
            case 2:
                display(sparseMatrix);
                break;
            case 3:
                printf("Enter row and column of the element to delete: ");
                scanf("%d %d", &row, &col);
                deleteNode(&sparseMatrix, row, col);
                break;
            case 4:
                printf("Enter row to delete: ");
                scanf("%d", &row);
                deleteRow(&sparseMatrix, row);
                break;
            case 5:
                printf("Enter column to delete: ");
                scanf("%d", &col);
                deleteColumn(&sparseMatrix, col);
                break;
            case 6:
                printf("Enter row number to insert and default value (0 for none): ");
                scanf("%d %d", &row, &val);
                insertRow(&sparseMatrix, row, val);
                break;
            case 7:
                printf("Enter column number to insert and default value (0 for none): ");
                scanf("%d %d", &col, &val);
                insertColumn(&sparseMatrix, col, val);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
