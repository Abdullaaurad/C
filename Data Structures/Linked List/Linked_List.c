#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct slinklist{
    int marks;
    char name[50];
    struct slinklist* next;
};

typedef struct slinklist node;

node *create_list(int number){
    int n;
    node *p, *head;
    printf ("How many elements to enter to list %d?",number);
    scanf ("%d", &n);
    if(n<=0){
        printf("The list is empty\n");
    }
    else{
        for (int k=0; k<n; k++) {
            if (k == 0) {
                head = (node *) malloc(sizeof(node));
                p = head;
            }
            else {
                p->next = (node *) malloc(sizeof(node));
                p = p->next;
            }
        printf("Enter the student name and marks  :");
        scanf ("%s %d",p->name,&p->marks);
        }
        p->next = NULL;
        return (head);
    }
}

node *concatenate(node *head1, node *head2){
    if(head1 == NULL){
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    node* curr = head1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head2;

    return head1;
}

void display (node *head,int number){
    int count = 1;
    node *p;
    p = head;
    if(p==NULL){
        printf("\n\n \t\tLIST %d",number);
        printf("\nThe list is empty");
    }
    else{
        printf("\n\n \t\tLIST %d",number);
        while (p != NULL){
            printf ("\nNode %d:\n      name:%s   age:%d",count,p->name,p->marks);
            count++;
            p = p->next;
        }
        printf ("\n");
    }
}

void free_list(node* head){
    node* current=head;
    node* next;
    while(current !=NULL){
 	 next=current->next;
	 free(current);
	 current=next;
    }
}

int main(){

    node* list1=create_list(1);
    node* list2=create_list(2);
    display(list1,1);
    display(list2,2);
    node* list3=concatenate(list1,list2);
    display(list3,3);

    free(list1);
    free(list2);
    free(list3);
 
    return 0;

}
