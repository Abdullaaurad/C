#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct slinklist{
    char name[50];
    int marks;
    struct slinklist* next;
};
typedef struct slinklist node;


void display(node *head){
    int count = 1;
    node *p;
    p=head;
    if(p==NULL){
        printf("\nThe list is empty");
    }
    else{
        printf("\n\n \t\tLIST ");
        while (p != NULL){
            printf ("\nNode %d:\n      name:%s   age:%d",count,p->name,p->marks);
            count++;
            p = p->next;
        }
    printf ("\n");
    }
}

void insert_q(node **head,char name[50],int *marks){
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->name,name);
    newnode->marks=*marks;
    newnode->next = *head;
    *head = newnode;
}

node *delete_q(node **head){
    if(*head==NULL){
        printf("The list is Empty");
        return NULL;
    }
    else{
        node* p=*head;
        node* q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        if(q==NULL){
            *head =NULL;
        }
        else{
            q->next=NULL;
        }
        return p;
    }
}

node* create_list(){
    return NULL;
}
int main(){
    char choice;
    node* list1=create_list();
    static int n=1;
    while(n==1){
        printf("To add a node Enter \"A\" to delete node Enter \"D\" to display list \"L\" Enter \"Q\" to quite:");
        scanf(" %c",&choice);
        if((choice=='Q')||(choice=='q')){
            n=0;
        }
        else if((choice=='A')||(choice=='a')){
            char name[50];
            int marks;
            printf("Enter the name and marks :");
            scanf("%s %d",name,&marks);
            insert_q(&list1,name,&marks);
        }
        else if((choice=='D')||(choice=='d')){
            node *deleted=delete_q(&list1);
            if(deleted !=NULL){
                printf("name:%s  marks:%d \n",deleted->name,deleted->marks);
            }
        }
        else if((choice=='L')||(choice=='l')){
            display(list1);
        }
        else{
            printf("invalid choice");
        }
    }

    node* current=list1;
    while(current!=NULL){
        node* temp=current;
        current = current->next;
        free(temp);
    }
    return 0;
}
