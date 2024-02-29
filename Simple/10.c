#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    printf("Enter how many words to check :");
    int m;
    scanf("%d",&m);

    FILE *fptr;
        fptr=fopen("D:\\myword.txt","w");
        if(fptr==NULL){
            printf("Error opening file");
            return 1;
        }
        fprintf(fptr,"Word\t\t a \t e \t i \t o \t u \t other \t total\n");
    
    for(int i=0;i<m;i++){
        int A_count=0;
        int E_count=0;
        int I_count=0;
        int O_count=0;
        int U_count=0;
        int other_count=0;

        printf("Enter the words :");
        getchar();
        char word[20];
        scanf("%s",word);

        int n=strlen(word);
        for(int i=0;i<n;i++){
            if(word[i]=='a'||word[i]=='A'){
                A_count++;
            }
            else if(word[i]=='e'||word[i]=='E'){
                E_count++;
            }
            else if(word[i]=='i'||word[i]=='I'){
                I_count++;
            }
            else if(word[i]=='o'||word[i]=='O'){
                O_count++;
            }
            else if(word[i]=='u'||word[i]=='U'){
                U_count++;
            }
            else{
                other_count++;
            }
        }
        fprintf(fptr,"\n%-10s \t %d \t %d \t %d \t %d \t %d \t   %d \t   %d",word,A_count,E_count,I_count,O_count,U_count,other_count,n);
         
    }
    fclose(fptr);
    return 0;
}