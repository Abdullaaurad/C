#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("give the line:");
    char words[100];
    fgets(words,sizeof(words),stdin);
    printf("\n%s",words);
    FILE *fptr;
    fptr=fopen("file2.txt","w");
    if(fptr==NULL){
        printf("Cant open file");
    }
    fprintf(fptr,"1.hi I am Abdulla\n");
    fprintf(fptr,"2.how are you");
    fclose(fptr);
    
    fptr=fopen("file2.txt","w");
    if(fptr==NULL){
        printf("Cant open file");
    }
    fprintf(fptr,"1.hi I am Abdulla\n");
    fprintf(fptr,"2.how are you\n");
    fprintf(fptr,"3.is it printed");
    fclose(fptr);

    fptr=fopen("file2.txt","r");
    if(fptr==NULL){
        printf("Cant open file");
    }
    char Array[20];
    fscanf(fptr,"%s",Array);
    printf("\n%s",Array);
    fclose(fptr);

    FILE *file;
    file=fopen("file2.txt","r");
    if(file==NULL){
        printf("Cant open file");
    }
    char s;
    printf("\n\t\tUsing getc\n");
    do{
        s=getc(file);
        printf("%c",s);
    }while(s!=EOF);
    fclose(file);


    FILE *new;
    new=fopen("file2.txt","r");
    if(new==NULL){
        printf("Cant open file");
    }
    char line[20];
    printf("\n\t\tUsing fgets\n");
    while(fgets(line,sizeof(line),file)!=NULL){        
        printf("%s",line);
    }
    fclose(file);

    FILE *fp;
    fp=fopen("file2.txt","r");
    fseek(fp,"hi",SEEK_END);
    printf("\nlocation of the string \"hi\" :%ld",ftell(fp));
    fclose(fp);

    fp=fopen("file2.txt","r");
    fseek(fp,"hi",SEEK_SET);
    printf("\nlocation of the string \"hi\" :%ld",ftell(fp));
    fclose(fp);

    fp=fopen("file2.txt","r");
    fseek(fp,"hi",SEEK_CUR);
    printf("\nlocation of the string \"hi\" :%ld",ftell(fp));
    fclose(fp);
    return 0;
}