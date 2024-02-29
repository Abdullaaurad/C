#include <stdio.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n&&arr[left]>arr[largest]) {
        largest=left;
    }
    if (right<n&&arr[right]>arr[largest]) {
        largest=right;
    }
    if (largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for (int i=n-1;i>0;i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int Array[]={1, 12,33, 9, 35, 17, 21};
    int n=sizeof(Array)/sizeof(Array[0]);

    printf("Original array: ");
    for (int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }

    heapSort(Array,n);

    printf("\nSorted array using HeapSort: ");
    for (int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }

    return 0;
}
