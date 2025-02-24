#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

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

int sumOfPrimesAtEvenIndices(struct Node* head) {
    int sum = 0, index = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (index % 2 == 0 && isPrime(temp->data)) {
            sum += temp->data;
        }
        temp = temp->next;
        index++;
    }
    return sum;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printList(head);
    
    int sum = sumOfPrimesAtEvenIndices(head);
    printf("Sum of prime numbers at even indices: %d\n", sum);

    return 0;
}
