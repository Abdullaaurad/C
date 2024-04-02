#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100

int TOP=-1;

bool isfull(){
    if(TOP>=MAX_SIZE-1){
        return true;
    }
    else{
        return false;
    }
}

bool isempty(){
    if(TOP==-1){
        return true;
    }
    else{
        return false;
    }
}

void push(char A,char stack[MAX_SIZE]){
    if(isfull()){
        printf("The stack is already full");
    }
    else{
        TOP=TOP+1;   //increase TOP
        stack[TOP]=A;   //Enter data to stack
    }
}

void pop(char k,char stack[MAX_SIZE]){
    if(isempty()){                          //
        printf("The stack isempty");
    }
    else{
        k=stack[TOP];
        printf("%c",stack[TOP]);
        TOP=TOP-1;
        //if you want to return the value we can use k
    }
}

int main(){
    int n;
    int validity;
    char stack[MAX_SIZE];
    char word[MAX_SIZE];
    char k;
    printf("Enter the word to reverse :");
    fgets(word,sizeof word,stdin);
    n=strlen(word);
    for(int i=0;i<n;i++){
        push(word[i],stack);
    }
    printf("The reversed word is :");
    for(int i=0;i<n;i++){
        pop(k,stack);
    }

    return 0;
}


