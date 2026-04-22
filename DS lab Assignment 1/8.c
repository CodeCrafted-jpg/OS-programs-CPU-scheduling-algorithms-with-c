#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print the list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// (a) Delete from the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* temp = head; 
    head = head->next;       
    free(temp);              
    return head;
}

// (b) Delete from the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    // Traverse until temp is the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next); 
    temp->next = NULL; 
    return head;
}

// (c) Delete a specified element
struct Node* deleteElement(struct Node* head, int val) {
    if (head == NULL) return NULL;

    // If the element to be deleted is the head
    if (head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    // Search for the node BEFORE the one to be deleted
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found.\n", val);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next; 
        free(toDelete);
    }
    return head;
}

// Helper function to create a small list
struct Node* createList() {
    struct Node *n1, *n2, *n3;
    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;
    return n1;
}

int main() {
    struct Node* head = createList();
    printf("Original List: "); display(head);

    // (a) Delete Start
    head = deleteAtBeginning(head);
    printf("After Delete Start: "); display(head);

    // Reset list for next demo
    head = createList(); 
    // (b) Delete End
    head = deleteAtEnd(head);
    printf("After Delete End: "); display(head);

    // Reset list for next demo
    head = createList();
    // (c) Delete 20
    head = deleteElement(head, 20);
    printf("After Deleting 20: "); display(head);

    return 0;
}
