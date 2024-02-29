#include <stdio.h>

void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main(){
    int my_array[]={3,4,9,5,1,2,10};
    int n=sizeof(my_array)/sizeof(my_array[0]);

    printf("Original array: ");
    for (int i=0;i<n;i++) {
        printf("%d ", my_array[i]);
    }
    selectionSort(my_array, n);
    printf("\nSorted array using Selection Sort: ");
    for (int i=0;i<n;i++){
        printf("%d ",my_array[i]);
    }
    return 0;
}
