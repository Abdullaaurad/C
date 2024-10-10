#include <stdio.h>

// Function to calculate the sum of squares of integers from a to b
int sumOfSquares(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += (i * i);  // Sum of squares
    }
    return sum;
}

int main() {
    int a, b, sum;

    // Input
    printf("Enter integers for a and b (a <= b): ");
    scanf("%d %d", &a, &b);

    // Validate that a <= b
    if (a > b) {
        printf("Error: a should be less than or equal to b.\n");
        return 1;  // Exit with error code
    }

    // Calculate sum of squares
    sum = sumOfSquares(a, b);

    // Output result
    printf("The sum of squares from %d to %d is: %d\n", a, b, sum);

    return 0;
}
