#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// (a) CREATE: Function to insert a node at the end
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

    struct Node* temp = head;
    // Traverse until we find the node that points back to head
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// (b) DELETE: Function to delete an element from the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;

    // If there is only one node
    if (temp->next == head) {
        free(temp);
        return NULL;
    }

    struct Node* prev = NULL;
    // Traverse until temp is the last node
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; 
    free(temp);       
    return head;
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    // Create
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printf("After Creation: ");
    display(head);

    // Delete from end
    head = deleteAtEnd(head);
    printf("After Deletion from End: ");
    display(head);

    return 0;
}
