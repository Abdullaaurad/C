#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct details{
    int Id_No;
    int Annual_Income;
    int Number_of_members;
};

int Average_income(struct details household[]){
    int sum=0;
    for(int i=0;i<5;i++){
        sum=sum+household[i].Annual_Income;
    }
    return (sum/5);
}

int total_members(struct details household[]){
    int count=0;
    for(int i=0;i<5;i++){
        count=count+household[i].Number_of_members;
    }
    return count;
}

int Median_income(struct details household[]){
    int median_point=(total_members(household)/2);
    int i=0;
    int count=0;
    if(count<median_point){
        count=count+household[i].Number_of_members;
        i++;
    }
    else{
        return (household[i].Annual_Income);
    }
}

int main(){

    FILE *fptr;
    fptr=fopen("D:\\readme.txt","r");
    if(fptr==NULL){
        printf("Error opening file");
        return 1;
    }

    struct details household[5];
    char Array[100];
    fgets(Array,sizeof(Array),fptr);

    for(int i=0;i<5;i++){
        fscanf(fptr,"%d %d %d",&household[i].Id_No,&household[i].Annual_Income,&household[i].Number_of_members);
    }
    fclose(fptr);
 
    printf("%s",Array);
    for(int i=0;i<5;i++){
        printf("%d\t\t%d\t\t     %d\n",household[i].Id_No,household[i].Annual_Income,household[i].Number_of_members);
    }

    int salary=Average_income(household);
    int count=total_members(household);

    printf("\nAverage household Income ($)- %d",salary);
    printf("\nTotal number of members in the town- %d",count);
    printf("\nMedian Annual Income ($)- %d",Median_income(household));
    return 0;
}