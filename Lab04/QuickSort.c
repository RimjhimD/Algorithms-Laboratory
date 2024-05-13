#include <stdio.h>

// Function to swap two elements
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int Partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[i + 1], &A[r]);
    return i + 1;
}

// Function to perform QuickSort
void QuickSort(int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
