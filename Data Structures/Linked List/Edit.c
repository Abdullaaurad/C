#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* InsertAtBegin(struct Node* last,int data){
    struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
    New_node->data=data;
    if(last==NULL){
        last=New_node;
        last->next=last;               //to check if list have any node if not insert new node
    }
    else{
        New_node->next=last->next;
        last->next=New_node;              //inserting the node at Beginning of the list
    }
    return last;
}

struct Node* InsertAtEnd(struct Node* last,int data){
    struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
    New_node->data=data;
    if(last==NULL){
        last=New_node;                     //To check if the list have any node if not insert Node
        last->next=last;
    }
    else{
        New_node->next=last->next;
        last->next=New_node;               //inserting the node at the last of the list
        last=New_node;
    }
    return last;
}

struct Node* deleteAtBegin(struct Node* last){
    if(last==NULL){
        printf("\nThe linked list is empty");           //checking whether the list has any node to delete
    }
    else{
        struct Node* ptr=last->next;
	if(ptr!=last){                                   //deleting th node in the beginning
           last->next=ptr->next;
           free(ptr);
	   ptr=NULL;
	}
	else{
	   free(last);
	   last=NULL;
	}
    }
    return last;
}

struct Node* deleteAtEnd(struct Node* last){
    if(last==NULL){
        printf("\nThe linked list is empty");            //checking whether the list has any node to delete
    }
    else{
        struct Node* ptr=last->next;
	if(ptr!=last){
            while(ptr->next!=last){
                ptr=ptr->next;                               ////deleting th node in the end
            }
            ptr->next=last->next;
            free(last);
            last=ptr;
	}
	else{
            free(last);
	    last=NULL;
	}
    }   
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
        printf("%d -> ",p->data);             //printing after insertion
        p=p->next;
    }while(p!=last);
    printf("%d -> ",last->data);
    printf("%d",last->next->data);


    last=deleteAtBegin(last);
    last=deleteAtEnd(last);

    struct Node* q=last;
    printf("\nAfter deletion :");
        do{
        printf("%d -> ",q->data);
        q=q->next;                               //printing after deletion
    }while(q!=last);
    printf("%d\n",last->data);
    
    struct Node* ptr;
    while(ptr!=NULL){
	ptr=last;
	last=last->next;
	free(ptr);
    }
    return 0;
}
