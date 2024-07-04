#include <stdio.h>
#include <string.h>

void preprocess_strong_suffix(int *shift, int *bpos, char *pat, int m) {
    int i = m, j = m + 1;
    bpos[i] = j;
    while (i > 0) {
        while (j <= m && pat[i - 1] != pat[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = bpos[j];
        }
        i--; 
        j--;
        bpos[i] = j;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    char pat[] = "ABABACA";
    int m = strlen(pat);
    int shift[m + 1];
    int bpos[m + 1];

    // Initialize arrays
    for (int i = 0; i <= m; i++) {
        shift[i] = 0;
        bpos[i] = 0;
    }

    // Call the preprocessing function
    preprocess_strong_suffix(shift, bpos, pat, m);

    // Print the results
    printf("Shift array: ");
    printArray(shift, m + 1);
    
    printf("Bpos array: ");
    printArray(bpos, m + 1);

    return 0;
}
