#include <stdio.h>

int main() {

    int i, j, arr[1000], n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Added & before arr[i] to correctly read the input.
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) { // Changed n-1 to n-i-1 to optimize the sorting loop.
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Added printing of sorted array.
    }
    printf("\n");

    return 0;
}


