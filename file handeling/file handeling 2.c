#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define N 100

struct Student{
    int roll_number;
    char name[50];
    float marks;
};

void Addrecord(){
    struct Student student;
    printf("Enter students Roll number :");
    scanf("%d",&student.roll_number);
    printf("Enter students name :");
    scanf("%s",student.name);
    printf("Enter students marks :");
    scanf("%f",&student.marks);

    FILE *fptr;
    fptr=fopen("D:\\student_records.txt","a");
    if(fptr==NULL){
        printf("Error opening the file");
        return;
    }

    fprintf(fptr, "%d %s %.2f \n",student.roll_number,student.name,student.marks);
    i=i+1;
    fclose(fptr);
}

void Displayrecord(){
    FILE *fptr;
    fptr=fopen("D:\\student_records.txt","r");
    if(fptr==NULL){
        printf("Error opening File\n");
        return;
    }
    struct Student student;
    printf("\t\tStudent Records :\n");

    while(fscanf(fptr,"%d %s %f",&student.roll_number,student.name,&student.marks)!=EOF){
        printf("Roll number: %d\n",student.roll_number);
        printf("Name: %s\n",student.name);
        printf("Marks: %.2f\n",student.marks);
        printf("\n");
    }

    fclose(fptr);
}

int Searchrecord(){
    int id;
    printf("Enter the roll number :");
    scanf("%d",&id);
    FILE *fptr;
    fptr=fopen("D:\\student_records.txt","r");
    if(fptr==NULL){
        printf("Error opening File\n");
        return -1;
    }
    struct Student Array[N];
    int i=0;
    while(fscanf(fptr,"%d %s %f",&Array[i].roll_number,Array[i].name,&Array[i].marks)!=EOF){
        i=i+1;
    }
    int found=0;
    for(int k=0;k<i;k++){
        if(Array[i].roll_number==id){
            printf("Roll number: %d\n",Array[i].roll_number);
            printf("Name: %s\n",Array[i].name);
            printf("Marks: %.2f\n",Array[i].marks);
            printf("\n");
            found=1;
            return k;
        }
    }
    if(found==0){
        printf("The id number is not in records\n");
    }
    return -1;
}

void Deleterecord(){
    printf("Enter the roll number to delete :");
    int id;
    scanf("%d",&id);

    FILE *fptr;
    fptr=fopen("D:\\student_records.txt","r");
    if(fptr==NULL){
        printf("Error opening File\n");
        return -1;
    }
    struct Student Array[N];
    int i=0;
    while(fscanf(fptr,"%d %s %f",&Array[i].roll_number,Array[i].name,&Array[i].marks)!=EOF){
        i=i+1;
    }
    fclose(fptr);
    int j=Searchrecord();
    for (j;j<i;j++){
        Array[j]=Array[j+1];
    }
    i=i-1;
    
    FILE *fptr;
    fptr=fopen("D:\\student_records.txt","w");
    if(fptr==NULL){
        printf("Error opening File\n");
        return -1;
    }
    for(int l=0;l<i;l++){
        fprintf(fptr, "%d %s %.2f \n",Array[l].roll_number,Array[l].name,Array[l].marks);
        i=i+1;
    }
}
int main(){
    int choice;
    do{
    printf("To add new student record Enter \"1\", Display all student records Enter \"2\", Display all student records \"3\", Display all student records Enter \"4\", To exit Enter \"5\" :");
    scanf("%d",&choice);

    if(choice==1){
        Addrecord();
    }

    else if(choice==2){
        Displayrecord();
    }

    else if(choice==3){
        int k=Searchrecord();
    }
     
    else if(choice==4){
        Deleterecord();
    }

    else{
        printf("\nInvalid choice choose Again"); 
    }

    }while(choice!=5);

    return 0;
}