#include <stdio.h>

void insertionSort(int arr[],int n){
    int key,j;
    for (int i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while (j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }

        arr[j+1]=key;
    }
}

int main() {
    int my_array[]={3,7,8,6,4,2,1};
    int n=sizeof(my_array)/sizeof(my_array[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }

    insertionSort(my_array, n);

    printf("\nSorted array using Insertion Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }

    return 0;
}
