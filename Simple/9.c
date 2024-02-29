#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

int main(){
    struct date day1;
    
    printf("enter the day of the date :");
    scanf("%d",&day1.day);
    printf("enter the month of the date :");
    scanf("%d",&day1.month);
    printf("enter the year of the date :");
    scanf("%d",&day1.year);
    
    day1.day=day1.day+45;
    if(day1.day/30==1){
        day1.month++;
        day1.day=day1.day-30;
    }
    else if(day1.day/30==2){
        day1.month=day1.month+2;
        day1.day=day1.day-60;
    }
    
    if(day1.month/12==1){
        day1.year++;
        day1.month=day1.month-12;
    }
    
    printf("The new day is : %d-%d-%d",day1.day,day1.month,day1.year);
    
}
