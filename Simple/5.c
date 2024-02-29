#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50]; // Use an array to store names
    int salary;
    int hours_of_work;
};

int main() {
    struct employee Arr[10];
    
    for (int i = 0; i < 3; i++) {   
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", Arr[i].name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%d", &Arr[i].salary);
        printf("Enter hours of work of employee %d: ", i + 1);
        scanf("%d", &Arr[i].hours_of_work);
    }
    
    for (int i = 0; i < 3; i++) { 
        if (Arr[i].hours_of_work == 8) {
            Arr[i].salary += 500;
        }
        else if (Arr[i].hours_of_work == 10) {
            Arr[i].salary += 1000;
        }
        else {
            Arr[i].salary += 1500;
        }
        printf("%s's salary = %d\n", Arr[i].name, Arr[i].salary);
    }

    return 0;
}