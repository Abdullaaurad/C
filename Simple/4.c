#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

int check(int m,char string[m],int n){
    for(int i=0;i<m;i++){
        switch (string[i]){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                n=n+1;
                break;
            default :
                break;
        }
    }
    return n;       
}
int main(){
    
    printf("Enter string :");
    char string[MAX_SIZE];
    fgets(string,sizeof(string),stdin);
    int m=strlen(string)-1;
    
    int n;
    n=check(m,string,n);
    printf("string contains %d vowels",n);
        
    return 0;
}
