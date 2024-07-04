#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 26

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++) {
        badchar[i] = -1;
    }
    for (i = 0; i < size; i++) {
        badchar[str[i] - 'A'] = i;
    }
}

void getBadCharTable(char *pat, int badchar[NO_OF_CHARS]) {
    int m = strlen(pat);
    badCharHeuristic(pat, m, badchar);
}

int main() {
    char pat[] = "ABDULLA";
    int badchar[NO_OF_CHARS];

    getBadCharTable(pat, badchar);
    printf("Bad character table:\n");
    for (int i = 0; i < NO_OF_CHARS; i++) {
        printf("%c: %d\n", 'A' + i, badchar[i]);
    }

    return 0;
}
