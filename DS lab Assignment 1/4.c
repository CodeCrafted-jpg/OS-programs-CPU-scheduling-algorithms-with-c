#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = 4; 

    int arr2[] = {2, 4, 6};
    int n2 = 3; 

    int n3 = n1 + n2; 
    int merged[n3];

    // Copy elements of the first array
    for (int i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements of the second array
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }

    // Display the merged array
    printf("Merged Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

