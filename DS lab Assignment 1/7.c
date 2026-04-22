#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// (a) Insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head; 
    return newNode;       
}

// (b) Insert at the end
void insertAtEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newNode; 
}

// (c) Insert at a specified position
void insertAtPosition(struct Node* head, int val, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    struct Node* temp = head;
    // Traverse to the node just before the target position
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
    } else {
        newNode->next = temp->next; 
        temp->next = newNode;       
    }
}

int main() {
    struct Node* head = NULL;

    // Initial node
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    printf("Original: "); display(head);

    // (a) Beginning
    head = insertAtBeginning(head, 5);
    printf("After Start: "); display(head);

    // (b) End
    insertAtEnd(head, 20);
    printf("After End: "); display(head);

    // (c) Position (Insert 15 at position 3)
    insertAtPosition(head, 15, 3);
    printf("After Pos 3: "); display(head);

    return 0;
}
