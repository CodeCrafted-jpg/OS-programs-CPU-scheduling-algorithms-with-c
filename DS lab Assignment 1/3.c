#include <stdio.h>

// BUBBLE SORT: Swaps adjacent elements if they are in the wrong order
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// SELECTION SORT: Finds the minimum element and places it at the beginning
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// INSERTION SORT: Builds the sorted array one item at a time (like sorting cards)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data1[] = {64, 25, 12, 22, 11}, n = 5;
    
    // Demonstrate Bubble Sort
    bubbleSort(data1, n);
    printf("Bubble Sorted: "); printArray(data1, n);

    // Demonstrate Selection Sort
    int data2[] = {64, 25, 12, 22, 11};
    selectionSort(data2, n);
    printf("Selection Sorted: "); printArray(data2, n);

    // Demonstrate Insertion Sort
    int data3[] = {64, 25, 12, 22, 11};
    insertionSort(data3, n);
    printf("Insertion Sorted: "); printArray(data3, n);

    return 0;
}
