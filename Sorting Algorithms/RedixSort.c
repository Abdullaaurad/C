#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[],int n) {
    int max=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countingSort(int arr[],int n,int exp){
    const int radix=10;
    int output[n];
    int count[radix]={0};

    for (int i=0;i<n;i++) {
        count[(arr[i] / exp) % radix]++;
    }

    for (int i=1;i<radix;i++) {
        count[i]+=count[i-1];
    }

    for (int i=n-1;i>=0;i--) {
        output[count[(arr[i]/exp)%radix]-1]=arr[i];
        count[(arr[i]/exp)%radix]--;
    }

    for (int i=0;i<n;i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[],int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int my_array[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }

    radixSort(my_array, n);

    printf("\nSorted array using Radix Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }

    return 0;
}
