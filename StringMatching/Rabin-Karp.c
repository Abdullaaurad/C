#include <stdio.h>
#include <string.h>

#define d 26


void rabinKarp(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int j,i;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M-1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {                //we use this to calculate the hash value of pattern and starting point where we start the comparisons hash value
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M) {
            t = (d*(t - txt[i]*h) + txt[i+M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char txt[] = "My Name is Abdulla";
    char pat[] = "is";
    int q = 101;
    rabinKarp(pat, txt, q);
    return 0;
}
