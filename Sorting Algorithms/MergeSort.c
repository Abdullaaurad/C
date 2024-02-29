#include <stdio.h>
#include <stdlib.h>

void Merge(int Arr[], int first, int middle, int last) {
    int x = middle - first + 1;
    int y = last - middle;

    int F[x];
    int L[y];

    for (int i = 0; i < x; i++) {
        F[i] = Arr[first + i];
    }
    for (int i = 0; i < y; i++) {
        L[i] = Arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = first;

    while (i < x && j < y) {
        if (F[i] <= L[j]) {
            Arr[k] = F[i];
            i++;
        } else {
            Arr[k] = L[j];
            j++;
        }
        k++;
    }

    while (i < x) {
        Arr[k] = F[i];
        i++;
        k++;
    }

    while (j < y) {
        Arr[k] = L[j];
        j++;
        k++;
    }
}

void MergeSort(int Arr[], int first, int last) {
    if (first < last) {
        int middle = first + (last - first) / 2;
        MergeSort(Arr, first, middle);
        MergeSort(Arr, middle + 1, last);
        Merge(Arr, first, middle, last);
    }
}

int main() {
    int Arr[] = {-5, 3, -2, 3, 2};
    int n = 5;

    MergeSort(Arr, 0, 4);

    printf("Arr[] = ");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d, ", Arr[i]);
        } else {
            printf("%d\n", Arr[i]);
        }
    }

    return 0;
}