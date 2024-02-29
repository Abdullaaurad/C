#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct details{
    char RegisterNo[20];
    char Name[50];
    int Age;
};

int main(){
    struct details student[5];

    for(int i=0;i<5;i++){
        printf("\t\t\tEnter the %d student detail",i+1);
        printf("\nEnter the student registration number :");
        fgets(student[i].RegisterNo,sizeof(student[i].RegisterNo),stdin);
        student[i].RegisterNo[strcspn(student[i].RegisterNo, "\n")] = '\0';
        printf("Enter the student name :");
        fgets(student[i].Name,sizeof(student[i].Name),stdin);
        student[i].Name[strcspn(student[i].Name, "\n")] = '\0';
        printf("Enter student Age :");
        scanf("%d",&student[i].Age);
        getchar();
    }

    FILE *fptr;
    fptr=fopen("D:\\File.txt","w");
    if(fptr==NULL){
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fptr, "%-21s%-51s%-11s\n", "StRe_no", "St_Name", "St_age");
    for(int i=0;i<5;i++){
        fprintf(fptr, "%-21s%-51s%-11d\n", student[i].RegisterNo, student[i].Name, student[i].Age);
    }

    return 0;
} 