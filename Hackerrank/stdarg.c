#include <stdio.h>
#include <stdarg.h>   //Allows the user to use the same function
                     // for function calls of different number of 
                     //parameters

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);

    return total;
}

int main() {
    printf("Sum: %d\n", sum(3, 5, 10, 15));
    printf("Sum: %d\n", sum(4, 2, 4, 6, 8));

    return 0;
}
