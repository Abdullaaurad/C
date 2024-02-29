#include <stdio.h>

int power(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum = sum + (i * i);
    }
    return sum;
}

int main() {
    int a;
    int b;
    int sum;
    printf("Enter integers for a and b: ");
    scanf("%d %d", &a, &b);
    sum = power(a, b);
    printf("The sum is: %d\n", sum);

    return 0;
}
