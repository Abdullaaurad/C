#include <stdio.h>
#include <string.h>

int Pi[100];

void Prefix(int m, char P[]){
    Pi[0] = 0;
    int k = 0;
    for(int q = 1; q < m; q++){
        while(k > 0 && P[k] != P[q])
            k = Pi[k - 1];
        if(P[k] == P[q]){
            k++;
        }
        Pi[q] = k;
    }
}

int kmpMatch(int m, int n, char P[], char T[]){
    int q = 0;
    for(int i = 0; i < n; i++){
        while(q > 0 && P[q] != T[i]){
            q = Pi[q - 1];
        }
        if(P[q] == T[i]){
            q++;
        }
        if(q == m){
            return i + 1 - m;
        }
    }
    return -1;
}

int main(){
    int n, m;
    printf("Enter size of the pattern = ");
    scanf("%d", &m);
    char Pattern[m + 1];
    printf("Enter Pattern = ");
    scanf("%s", Pattern);

    printf("Enter size of the text = ");
    scanf("%d", &n);
    char Text[n + 1];
    printf("Enter text = ");
    scanf("%s", Text);

    printf("Text = %s\n", Text);
    printf("Pattern = %s\n", Pattern);

    Prefix(m, Pattern);
    printf("The Prefix Table = ");
    for(int i = 0; i < m; i++){
        printf("%d ", Pi[i]);
    }

    int l = kmpMatch(m, n, Pattern, Text);
    if(l == -1){
        printf("\nPattern is not found in text");
    }
    else{
        printf("\nPattern is found at index = %d", l);
    }
    return 0;
}
