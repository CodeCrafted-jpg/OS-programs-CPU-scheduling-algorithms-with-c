#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// (a) CREATE: Function to insert a node at the end
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode; 
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// (b) SEARCH: Function to find an element
void search(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;
    
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to display the list (Forward)
void display(struct Node* head) {
    struct Node* temp = head;
    printf("DLL: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating the list
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    display(head);

    // Searching for elements
    search(head, 30); 
    search(head, 99); 

    return 0;
}
