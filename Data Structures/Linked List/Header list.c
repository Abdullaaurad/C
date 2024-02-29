#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* deleteLinkedList(struct Node *head){
    struct Node* p=head;
    if(p!=NULL){
        deleteLinkedList(p->next);      //to delete every node in the list
        free(p);
    }
    head=NULL;
    return head;
}

struct Node* sortLinkedList(struct Node* head){
    int swapped;                                     //to keep track of the swap is at end or not
    struct Node* current;
    struct Node* tail = NULL;
    if (head == NULL)
        return NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != tail) {
            if (current->data < current->next->data) {
                int temp=current->data;                           //swapping the data
                current->data=current->next->data;
                current->next->data=temp;
                swapped = 1;
            }
            current = current->next;
        }
        tail = current;
    }while(swapped);
    return NULL;
}

int main(){
    struct Node* head=NULL;
    int n;
    struct Node* p;
    struct Node* q;

    printf("\n How many data to be inserted  :");
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        if(k==0){
            head=(struct Node*)malloc(sizeof(struct Node));
            p=head;
        }
        else{
            p->next=(struct Node*)malloc(sizeof(struct Node));
            p=p->next;
        }
        printf("Enter data to insert into the linked list  :");
        scanf("%d",&p->data);
    }
    p->next=NULL;
    struct Node* list=head;
    //End of creating the list

    list=sortLinkedList(list);
    //sorting of the list

    q=head;
    while(q!=NULL){
        printf("%d",q->data);
        if(q->next!=NULL){
            printf(" -> ");
        }
        q=q->next;
    }
    //printing the list

    list=deleteLinkedList(list);
    //deleting the list

    if(list==NULL){
        printf("\nLinked list is deleted\n");
    }
    //to check whether the list is deleted

    struct Node* r;
    while(head!=NULL){
        r=head;
        head=head->next;
        free(r);
	r=NULL;
    }
    return 0;
}

