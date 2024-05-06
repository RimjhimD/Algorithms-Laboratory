//Merge Sort Algorithm
  
 #include <stdio.h>

void Merge(int A[], int p, int q, int r);

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    L[n1] = 9999999; // Sentinel value to mark the end of array L
    R[n2] = 9999999; // Sentinel value to mark the end of array R

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {20, 40, 60, 45, 34, 80};
    int arr_size = sizeof(array) / sizeof(array[0]);
    printf("Given array is \n");
    printArray(array, arr_size);

    MergeSort(array, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(array, arr_size);
    //printf("Number of division into Merge Sort: ");
    return 0;
}
