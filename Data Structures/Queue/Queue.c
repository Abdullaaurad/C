#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SONGS 1000
#define MAX_SIZE 100

int FRONT=-1;
int REAR=-1;
char QUEUE[MAX_SONGS][MAX_SIZE];
int n;

int isFull(){
    if(REAR==MAX_SONGS-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(FRONT==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(char inputs[MAX_SIZE]){
    if(isFull()){
        printf("Queue is full can't add more songs");
    }
    else{
        if(isEmpty()){
            FRONT=0;
        }
        REAR++;
        for(int i=0;i<n;i++){
            QUEUE[REAR][i]=inputs[i];
        }
    }
}

void DisplayQueue(){
    if(isEmpty()){
        printf("The Queue is empty");
    }
    else{
        printf("The Songs in the playlists are:\n");
        for(int i=FRONT;i<=REAR;i++){
            for(int k=0;k<MAX_SIZE;k++){
                printf("%c",QUEUE[i][k]);
            }
        printf("\n");
        }
    }
}

int main(){
    char inputs[MAX_SIZE];
    printf("Enter song name or enter \'Q\' to stop entering songs:");
    while(1){    
        fgets(inputs,sizeof(inputs),stdin);
        n=strlen(inputs)-1;

        if((n==1)&&((inputs[0]=='Q')||(inputs[0]=='q'))){
            printf("All the songs are added to the playlist\n");
            break;
        }
        else{
            Enqueue(inputs);
        }
    }
    printf("To play the songs in the playlist enter \'P\'  :");
    char k;
    scanf("%c",&k);
    if((k=='P')||(k=='p')){
	DisplayQueue();}
    return 0;
}
