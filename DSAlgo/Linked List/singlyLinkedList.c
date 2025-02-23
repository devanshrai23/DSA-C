#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_atStart(Node* head, int val) {    //O(1)
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insert_atEnd(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* delete_atStart(Node* head) {     //O(1)
    if(head == NULL) {
        printf("The list is already empty!\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delete_atEnd(Node* head) {
    if(head == NULL) {
        printf("The list is already empty!\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* curr = head, *prev;
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

Node* insert_atPos(Node* head,int val,int pos){
    if(pos < 0) {
        printf("Invalid Position!\n");
        return head;
    }
    if(pos == 0) {
        head = insert_atStart(head,val);
        return head;
    }
    Node* temp = head;
    for(int i=0;i<pos-1;i++) {
        if(temp == NULL) {
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

Node* delete_atPos(Node* head, int pos) {    //O(n)
    if (head == NULL || pos < 0) {
        printf("Invalid Position or Empty List!\n");
        return head;
    }
    if (pos == 0) {
        return delete_atStart(head);
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 0; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bound!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

Node* delete_Node(Node* head, int key) {
    if(head == NULL) {
        return head;
    }
    Node* prev = NULL;
    if(head->data == key) {
        prev = head;
        head = head->next;
        free(prev);
        return head;
    }
    Node* curr = head;
    while(curr!=NULL && curr->data!=key) {
        prev = curr;
        curr = curr->next;
    }
    if(curr = NULL) {
        printf("Data does not exist!");
        return head;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}

int length(Node *head) {
    if(head == NULL) {
        return 0;
    }
    return (1 + length(head->next));
}

Node* reverseList(Node* head){
    Node *prev=NULL, *curr=head, *next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* middleNode(Node *head) {
    Node* slow = head, *fast = head;
    while(fast->next != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int search(Node*head, int key) {       // O(n)
    if(head == NULL) {
        printf("The list is already empty!\n");
    }
    Node* temp = head;
    int index = 0;
    while(temp != NULL) {
        if(temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

Node* deleteDuplicates(Node* head){     //if the list is sorted
    Node *prev = head, *curr = head->next;
    while(curr != NULL){
        if(prev->data == curr->data){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

Node* delete_alternate_nodes(Node* head) {
    if (head == NULL) return NULL;
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
    return head;
}

bool hasCycle(Node* head) {
    Node* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

Node* detectCycle(Node* head) {
    Node* slow = head, *fast = head;
    bool isCycle = false;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
        return NULL;
    }
    slow = head;
    // Node* prev = NULL;
    while(slow != fast){
        slow = slow->next;
        // prev = fast;
        fast = fast-> next;
    }
    // prev->next = NULL;      // remove cycle
    return slow;
}

Node* delete_alternate_nodes(Node* head) {
    if (head == NULL) return NULL;
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
    return head;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;
    
    // Find the middle of the list
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half of the list
    Node *prev = NULL, *curr = slow, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Compare both halves
    Node* first = head;
    Node* second = prev;
    while (second != NULL) {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
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
    Node* head = NULL;

    head = insert_atStart(head, 2);
    displayList(head);
    head = insert_atStart(head,2);
    displayList(head);
    head = insert_atEnd(head,3);
    displayList(head);
    head = insert_atPos(head,3,2);
    displayList(head);
    head = reverseList(head);
    displayList(head);
    head = deleteDuplicates(head);
    displayList(head);
    printf("Length of Linked List : %d\n",length(head));
    return 0;
}
