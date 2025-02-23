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

Node* insert_atPos(Node* head, int val, int pos) {
    if (pos < 0) {
        printf("Invalid Position!\n");
        return head;
    }
    if (pos == 0) {
        return insert_atStart(head, val);
    }

    if (head == NULL) {
        printf("Position out of bound!\n");
        return head;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {
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

Node* concatLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* resultHead = NULL;
    if (head1->data <= head2->data) {
        resultHead = head1;
        resultHead->next = mergeSortedLists(head1->next, head2);
    } else {
        resultHead = head2;
        resultHead->next = mergeSortedLists(head1, head2->next);
    }

    return resultHead;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NULL, *head2 = NULL;

    head1 = insert_atPos(head1, 1, 0);
    head1 = insert_atPos(head1, 3, 1);
    head1 = insert_atPos(head1, 5, 2);
    printf("List1: ");
    displayList(head1);

    head2 = insert_atPos(head2, 2, 0);
    head2 = insert_atPos(head2, 4, 1);
    head2 = insert_atPos(head2, 6, 2);
    printf("List2: ");
    displayList(head2);

    // printf("Merged List: ");
    // Node* mergeHead = mergeSortedLists(head1, head2);
    // displayList(mergeHead);

    printf("Concatenated List: ");
    Node* concatHead = concatLists(head1, head2);
    displayList(concatHead);

    return 0;
}
