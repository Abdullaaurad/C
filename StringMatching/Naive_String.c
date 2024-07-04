#include <stdio.h>

int StringMatching(int n, int m, char Text[], char Pattern[]){
    for(int i = 0; i <= n - m; i++){
        int j = 0;
        while(j < m && Text[i + j] == Pattern[j]){
            j++;
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, m;

    printf("Enter Text size: ");
    scanf("%d", &n);
    printf("Enter the Text: ");
    char Text[n + 1];
    scanf("%s", Text);

    printf("Enter Pattern size: ");
    scanf("%d", &m);
    printf("Enter the Pattern: ");
    char Pattern[m + 1];
    scanf("%s", Pattern);

    int result = StringMatching(n, m, Text, Pattern);
    if(result != -1){
        printf("The index where the Pattern is found: %d\n", result);
    } else {
        printf("Pattern is not found in the text\n");
    }

    return 0;
}
