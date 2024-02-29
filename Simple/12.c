#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct details{
    char Employee_Name[10];
    int Employee_No;
    float Basic_Salary;
    int OT_hours;
    float OT_amount;
    float Net_Salary;
};

void calculate(struct details employee[]){
    for(int i=0;i<4;i++){
        employee[i].OT_amount=employee[i].OT_hours*15;
        employee[i].Net_Salary=(employee[i].Basic_Salary*1.35)+employee[i].OT_amount;
    }
}

int main(){
    struct details employee[4];
    FILE *fptr;

    fptr=fopen("D://data.txt","r");
    if(fptr==NULL){
        printf("Error opening the file");
        return 1;
    }
    for(int i=0;i<4;i++){
        fscanf(fptr, "%s %d %f %d",employee[i].Employee_Name,employee[i].Employee_No,employee[i].Basic_Salary,employee[i].OT_hours);
    }
    fclose(fptr);

    calculate(employee);

    printf("Employee No\t Basic Salary\t OT amount\t Net Salary");
    for(int i=0;i<4;i++){
        printf("%d %f %f %f",employee[i].Employee_No,employee[i].Basic_Salary,employee[i].OT_amount,employee[i].Net_Salary);
    }
    return 0;

}