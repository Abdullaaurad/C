#include<stdio.h>
#include<time.h>
#include<stdlib.h>
    
void start(){
    printf("let's play a rock paper scissors game");
    srand(time(0));
    int random=rand();
    random=(random%3)+1;
    int choise;
    printf("Enter 1 for rock, 2 for paper and 3 for scissors ");
    scanf("%d",&choise);
    
    if(choise==random){
        printf("This match was a tie\n");
    }
    else if((choise==1)&&(random==3)){
        printf ("You have won the game\n");
    }
    else if((choise==2)&&(random==1)){
        printf ("You have won the game\n");
    }
    else if((choise==3)&&(random==2)){
        printf ("You have won the game\n");
    }
    else if((choise==1)&&(random==2)){
        printf ("You have lost the game\n");
    }
    else if((choise==2)&&(random==3)){
        printf ("You have lost the game\n");
    }
    else if((choise==3)&&(random==1)){
        printf ("You have lost the game\n");
    }
    else{
        printf("you have entered a invalid number\n");
    }
}
int main(){
    int p=1;
    while(p==1){   
        printf("\nEnter 1 to play game and 0 to quite game :");
        int p;
        scanf("%d",&p);
        if(p==1){
            start();
        }
        else{
            printf("you have quited the game");
            p=0;
            return p;
        }
    }
}
