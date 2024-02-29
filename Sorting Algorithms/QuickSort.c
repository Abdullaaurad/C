#include <stdio.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high) {
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++) {
        if (arr[j]<=pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i + 1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high) {
    if (low<high) {
        int pivotIndex=partition(arr,low,high);

        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);
    }
}

int main() {
    int my_array[]={3,6,8,10,1,2,1};
    int n=sizeof(my_array)/sizeof(my_array[0]);

    printf("Original array: ");
    for(int i=0;i<n;i++) {
        printf("%d ",my_array[i]);
    }

    quicksort(my_array,0,n - 1);

    printf("\nSorted array: ");
    for (int i =0;i<n;i++){
        printf("%d ", my_array[i]);
    }

    return 0;
}
