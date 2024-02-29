#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESS 1000
#define MAX_SIZE 100
int FRONT_H=-1;
int REAR_H=-1;
int FRONT_L=-1;
int REAR_L=-1;
char QUEUE_HIGH[MAX_PROCESS][MAX_SIZE];
char QUEUE_LOW[MAX_PROCESS][MAX_SIZE];
int n;

int isFull_H(){
    if(REAR_H==MAX_PROCESS-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty_H(){
    if(FRONT_H==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull_L(){
    if(REAR_L==MAX_PROCESS-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty_L(){
    if(FRONT_L==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(char inputs[MAX_SIZE],int l){
    if(l==1){
        if(isFull_H()){
            printf("High priority queue is full can't add more processes");
        }

        else{
            if(isEmpty_H()){
                FRONT_H=0;
            }
            REAR_H++;
            for(int i=0;i<n;i++){
                QUEUE_HIGH[REAR_H][i]=inputs[i];}
        }
    }

    else if(l==0){
        if(isFull_L()){
            printf("Low priority queue is full can't add more processes");
        }

        else{
            if(isEmpty_L()){
                FRONT_L=0;
            }
            REAR_L++;
            for(int i=0;i<n;i++){
                QUEUE_LOW[REAR_L][i]=inputs[i];}

        }
    }
    else{
        printf("Entered priority is not valid");
    }
}
void DisplayQueue(char printing){
    if((printing=='H')||(printing=='h')||(printing=='T')||(printing=='t')){
    	if(isEmpty_H()){
           printf("High priority Queue is empty");
    	}
    	else{
           printf("\n\nHigh priority processes:\n");
           int A=1;
           for(int i=FRONT_H;i<=REAR_H;i++){

              printf("%d.",A);
              A++;
              for(int k=0;k<MAX_SIZE;k++){
                 printf("%c",QUEUE_HIGH[i][k]);
              }
	   printf("\n");   
           }
        }
    }
    else if((printing=='L')||(printing=='l')||(printing=='T')||(printing=='t')){
    	if(isEmpty_L()){
           printf("\n\nLow priority Queue is empty");
        }
        else{
           printf("\n\nLow priority processes:\n");
           int B=1;
           for(int i=FRONT_L;i<=REAR_L;i++){

               printf("%d.",B);
               B++;
               for(int k=0;k<MAX_SIZE;k++){
                  printf("%c",QUEUE_LOW[i][k]);
               }
	   printf("\n");
           }
        }
    }
    else{
	 printf("You have eneterd a invalid character");
    }
}

int main(){
    char inputs[MAX_SIZE];
    printf("Enter \'Q\' to stop entering processes:");
    while(1){
        printf("Enter the process:");
        fgets(inputs,sizeof(inputs),stdin);
        n=strlen(inputs)-1;

        if((n==1)&&((inputs[0]=='Q')||(inputs[0]=='q'))){
            printf("Successfully quited the program\n");
            break;
        }
        else{
            printf("Enter 0 if priority is low and enter 1 if priority is high:");
	    int l;
            scanf("%d",&l);
            getchar();
            Enqueue(inputs,l);
	    printf("\n");

        }
    }
    int count=0;
    while(count<2){
       printf("\nEnter \'H\' to view the high priority processes and enter \'L\' to view the low priority processes and enter \'T\' to view all the processes :  ");
       char printing;
       scanf("%c",&printing);
       DisplayQueue(printing);
       count=count+1;
       getchar();
    }
    return 0;
}
