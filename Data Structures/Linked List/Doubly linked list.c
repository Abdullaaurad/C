#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* InsertAtBegin(struct Node* last,int data){
    struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
    New_node->next=NULL;
    New_node->prev=NULL;
    New_node->data=data;
    if(last==NULL){
        last=New_node;                          //checking whether the list has any node
        last->next=last;
        last->prev=last;
    }
    else{
        struct Node* ptr=last;
        ptr=last->next;                          //inserting the node to the beginning
        last->next=New_node;
        New_node->next=ptr;
        ptr->prev=New_node;
        New_node->prev=last;
    }
    return last;
}

struct Node* InsertAtEnd(struct Node* last,int data){
    struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
    New_node->next=NULL;
    New_node->prev=NULL;
    New_node->data=data;
    if(last==NULL){                             //checking whether the list has any node
        last=New_node;
        last->next=last;
        last->prev=last;
    }
    else{
        struct Node* ptr=last;
        ptr=ptr->next;                          //inserting the node to the End
        last->next=New_node;
        New_node->next=ptr;
        ptr->prev=New_node;
        New_node->prev=last;
        last=New_node;
    }
    return last;
}

struct Node* DeleteAtBegin(struct Node* last){
    if(last==NULL){
        printf("the doubly linked list is empty");                    //checking the list is empty or not
        return NULL;
    }
    struct Node* ptr=last->next;
    struct Node* prepter=ptr->next;
                                                                      //deleting the node in the beginning
    last->next=prepter;
    prepter->prev=last;
    free(ptr);
    ptr=NULL;
    return last;
}


struct Node* DeleteAtEnd(struct Node* last){
    if(last==NULL){                                                     //checking the list is empty or not
        printf("the doubly linked list is empty");
        return NULL;
    }
    struct Node* ptr=last->next;
    struct Node* prepter=last->prev;                                    //deleting the node in the End

    prepter->next=ptr;
    ptr->prev=prepter;
    free(last);
    last=NULL;
    last=prepter;
    return last;
}

int main(){
    struct Node* last=NULL;

    last=InsertAtEnd(last,10);
    last=InsertAtEnd(last,20);
    last=InsertAtEnd(last,30);

    printf("After insertion :");
    struct Node* p=last->next;
    do{
        printf("%d <-> ",p->data);
        p=p->next;                                              //printing the list after insert
    }while(p!=last);
    printf("%d <-> ",last->data);
    printf("%d",last->next->data);

    last=DeleteAtBegin(last);
    last=DeleteAtEnd(last);

    struct Node* q=last;
    printf("\nAfter deletion :");                               //printing the list after deleting
    do{
        printf("%d <-> ",q->data);
        q=q->next;
    }while(q!=last);
    printf("%d\n",last->data);
 
    struct Node* hi;
    last->next->prev=NULL;
    while(last!=NULL){
         hi=last;
         last=last->prev;
         free(hi);
         hi=NULL;
    }

}
