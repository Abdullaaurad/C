#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct day {
    int date;
    int month;
    int year;
};

int compare(struct day day1, struct day day2) {
    int n = 1;
    if (day1.date != day2.date || day1.month != day2.month || day1.year != day2.year) {
        n = 0;
    }
    return n;
}

int main() {
    struct day day1;
    struct day day2;

    // Input for day1
    printf("Enter the date of day 1: ");
    scanf("%d", &day1.date);
    printf("Enter the month of day 1: ");
    scanf("%d", &day1.month);
    printf("Enter the year of day 1: ");
    scanf("%d", &day1.year);
    printf("\n");

    // Input for day2
    printf("Enter the date of day 2: ");
    scanf("%d", &day2.date);
    printf("Enter the month of day 2: ");
    scanf("%d", &day2.month);
    printf("Enter the year of day 2: ");
    scanf("%d", &day2.year);
    printf("\n");

    int k = compare(day1, day2);
    if (k == 0) {
        printf("Dates are not equal");
    } else {
        printf("Dates are equal");
    }

    return 0;
}

