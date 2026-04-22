#include <stdio.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int n = 5; // Current size
    int pos, val, i;

    // --- INSERTION OPERATION ---
    // Target: Insert value 25 at position 3 (index 2)
    pos = 3; 
    val = 25;
    
    // Shift elements to the right
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val; // Insert the value
    n++; // Increase size

    printf("After Insertion: ");
    display(arr, n);

    // --- DELETION OPERATION ---
    // Target: Delete element at position 2 (index 1)
    pos = 2;

    if (pos > n || pos < 1) {
        printf("Invalid position!\n");
    } else {
        // Shift elements to the left
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // Decrease size
    }

    printf("After Deletion: ");
    display(arr, n);

    return 0;
}
