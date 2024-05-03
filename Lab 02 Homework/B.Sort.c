#include<stdio.h>

int main() {
    int i,j,n,t,flag,arr[10000];

    //printf("Enter the number of the elements: ");
    scanf("%d", &n);

    //int arr[n];

    //printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort algorithm
    for(i = 0; i < n-1; i++) {
            flag = 0;
        for(j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {

                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;

                 flag = 1;
            }
        }

        if(flag == 0){
            break;
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
