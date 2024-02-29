#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct slinklist{
    char name[50];
    int marks;
    struct slinklist* next;
};
typedef struct slinklist node;

void insert_soretd(node **head,const char* name,int marks){
    node* p=(node*)malloc(sizeof(node));
    p->marks=marks;
    strncpy(p->name,name,sizeof(p->name)-1);
    p->next=NULL;

    if((*head==NULL)||((*head)->marks >=p->marks)){
        p->next=*head;
        *head=p;
    }
    else{
        node* current=*head;
        while((current->next!=NULL)&&(current->next->marks < p->marks)){
            current= current->next;
        }
        p->next= current->next;
        current->next=p;
    }
}

void display (node *head){
    int count = 1;
    node *p;
    p = head;
    if(p==NULL){
        printf("The list is empty");
    }
    else{
        printf("LIST\n");
        while (p != NULL){
            printf ("Name:%s   marks:%d\n",p->name,p->marks);
            count++;
            p = p->next;
        }
        printf ("\n");
    }
}


int main()
{
     static char character='A';
     node* list=NULL;
     printf("To enter elements enter \'A\' to exit enter \'Q\'  :");
     scanf(" %c",&character);
     while((character!='Q')&&(character!='q')){
        if((character=='A')||(character=='a')){
            char name[50];
            int marks;
            printf("Enter Students name and marks  :");
            scanf("%s %d",name,&marks);
            insert_soretd(&list,name,marks);
            printf("To enter elements enter \'A\' to exit enter \'Q\'  :");
            scanf(" %c",&character);
        }
        else{
            printf("invalid character \n");
            printf("To enter elements enter \'A\' to exit enter \'Q\'  :");
            scanf(" %c",&character);
        }
     }

     display(list);

     node* current=list;
     while(current!=NULL){
        node* temp=current;
        current = current->next;
        free(temp);
     }

    return 0;
}
