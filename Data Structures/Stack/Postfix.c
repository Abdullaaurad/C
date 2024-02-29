#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100

int TOP=-1;
 int k;

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

void push(int A,int stack[MAX_SIZE]){
    if(isfull()){
        printf("The stack is already full");
    }
    else{
        TOP=TOP+1;
        stack[TOP]=A;
    }
}

void pop(int stack[MAX_SIZE]){
    if(isempty()){
        printf("\nThe stack isempty");
    }
    else{
        k=stack[TOP];
        TOP=TOP-1;
    }
}

int main(){
    int n;
    int stack[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the postfix :");
    fgets(postfix,sizeof postfix,stdin);
    n=strlen(postfix);
    char number[MAX_SIZE];

    for(int i=0;i<n;i++){
        if((postfix[i]=='0')||(postfix[i]=='1')||(postfix[i]=='2')||(postfix[i]=='3')||(postfix[i]=='4')||(postfix[i]=='5')||(postfix[i]=='6')||(postfix[i]=='7')||(postfix[i]=='8')||(postfix[i]=='9')){
            int m;
            m=postfix[i]-'0';
            push(m,stack);
        }
        else if((postfix[i]=='*') || (postfix[i]=='+') || (postfix[i]=='-') || (postfix[i]=='/')){
            char opera=postfix[i];
            int n1;
            int n2;
            int n3;
            pop(stack);
            n1=k;
            pop(stack);
            n2=k;

            switch(opera){
                case '+':
                    n3=n2+n1;
                    push(n3,stack);
                    break;
                case '-':
                    n3=n2-n1;
                    push(n3,stack);
                    break;
                case '*':
                    n3=n2*n1;
                    push(n3,stack);
                    break;
                default:
                    n3=n2/n1;
                    push(n3,stack);
            }
        }
    }

    if(TOP==0){
        printf("\nEvaluation of the postfix is :%d",stack[0]);
    }
    return 0;
}

