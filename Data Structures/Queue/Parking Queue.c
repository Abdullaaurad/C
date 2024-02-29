#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 10
int Front=-1;
int Rear=-1;
int FrontWaite=-1;
int RearWaite=-1;

struct car{
    int moves;
    char license_plate[6];
};

struct car Queue[MAX_SIZE];
struct car waite[100];

bool Isfull(){
    if(Rear==MAX_SIZE-1){
        return true;
    }
    else{
        return false;
    }
}

bool Isempty(){
    if(Front==-1){
        return true;
    }
    else{
        return false;
    }
}

bool IsemptyW(){
    if(FrontWaite==-1){
        return true;
    }
    else{
        return false;
    }
}

void Enqueuewaite(char license_plate[]){
    if(IsemptyW()){
        FrontWaite=0;
    }
    RearWaite++;
    strcpy(waite[Rear].license_plate,license_plate);
}

void Enqueue(char license_plate[]){
    if(Isfull()){
        printf("\nThere is no room for the car");
        printf("\nAdded car to the waiting list");
        Enqueuewaite(license_plate);
    }
    else{
        printf("\nThe car's been added to the parking");
        if(Isempty()){
            Front=0;
        }
        Rear++;
        strcpy(Queue[Rear].license_plate, license_plate);
        Queue[Rear].moves++;
    }
}

struct car DequeueW(){
    struct car temp=waite[FrontWaite];
    printf("The car that has %s number is been added to the parking from the waiting line",waite[FrontWaite].license_plate);
    int i=FrontWaite; 
    while(i<=RearWaite){
        waite[i]=waite[i+1];
        i++;
    }
    return temp;
}

void Dequeue(char license_plate[]){
    if(Isempty()){
        printf("\nThere are no cars in the parking");
    }
    int j=0;
    while((j<=Rear)&&(strcmp(Queue[j].license_plate,license_plate))){
        j=j+1;
    }
    printf("\nThere is a space to park the car");
    if(j>Rear){
        printf("\nThere are no cars in this license plate number");
    }
    else{
        int i=0;
        while(i<j){
            Queue[i].moves++;
            i=i+1;
        }
        printf("\nThe cars license plate number :%s",Queue[j].license_plate);
        printf("\nThe number of times the car is been moved is:%d",Queue[j].moves);
        while(j<=Rear-1){
            Queue[j].moves++;
            strcpy(Queue[j].license_plate,Queue[j+1].license_plate);
        }
        if(IsemptyW()){
            Rear--;
        }
        else{
            Queue[i]=DequeueW();
        }
    }
}


int main(){
    char c;
    do{
        printf("\nTo add a car enter \'a\' to remove a car enter \'d\' to quite enter \'q\':");
        scanf(" %c",&c);
        getchar();
        if(c=='a'){
            printf("\nEnter the license plate number of the car :");
            char Number[7];
            scanf(" %6s",Number);
            Enqueue(Number);
        }
        else if(c=='d'){
            printf("\nEnter the license plate number of the car :");
            char Number[7];
            scanf(" %6s",Number);
            Dequeue(Number);
        }
    }while(c!='q');
    return 0;
}