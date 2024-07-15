#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void preprocess_shift_table(const char *pattern, int shift_table[]) {
    int m = strlen(pattern);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        shift_table[i] = m;
    for (int j = 0; j < m - 1; j++) {
        shift_table[(unsigned char)pattern[j]] = m - 1 - j;
    }
}

int horsepool_string_match(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shift_table[ALPHABET_SIZE];

    preprocess_shift_table(pattern, shift_table);

    int i = m - 1;  // Start with the end of the pattern aligned with the text

    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;  // Pattern found, return the starting index
        } else {
            i += shift_table[(unsigned char)text[i]];  // Shift the pattern
        }
    }

    return -1;  // Pattern not found
}

int main() {
    const char *text = "this is a simple example";
    const char *pattern = "example";

    int result = horsepool_string_match(text, pattern);

    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
