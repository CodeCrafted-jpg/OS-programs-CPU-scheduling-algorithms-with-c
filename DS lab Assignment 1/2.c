#include <stdio.h>

// Linear Search: Checks elements sequentially
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

// Binary Search: Halves the search space (Iterative)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() {
   
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int target = 30;

    // Perform Linear Search
    int linIdx = linearSearch(arr, n, target);
    if (linIdx != -1)
        printf("Linear Search: Found %d at index %d\n", target, linIdx);
    else
        printf("Linear Search: Element not found\n");

    // Perform Binary Search
    int binIdx = binarySearch(arr, n, target);
    if (binIdx != -1)
        printf("Binary Search: Found %d at index %d\n", target, binIdx);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
