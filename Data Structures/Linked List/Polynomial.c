#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* head,int coeff,int exp){
    struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
    New_node->coeff=coeff;
    New_node->exp=exp;
    New_node->next=NULL;
    if(head==NULL){
        head=New_node;
    }
    else{
        struct Node* p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=New_node;
    }
    return head;
}

struct Node* addPolynomials(struct Node* poly1,struct Node* poly2){
    struct Node* head=NULL;
    while((poly1!=NULL)&&(poly2!=NULL)){
        struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
        New_node->exp=(poly1->exp);
        New_node->coeff=(poly1->coeff)+(poly2->coeff);
        New_node->next=NULL;

        if(head==NULL){
            head=New_node;
        }
        else{
            struct Node* p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=New_node;
        }
        poly1=poly1->next;
        poly2=poly2->next;
    }
    return head;
}

struct Node* subtractPolynomials(struct Node* poly1,struct Node* poly2){
    struct Node* head=NULL;
    while((poly1!=NULL)&&(poly2!=NULL)){
        struct Node* New_node=(struct Node*)malloc(sizeof(struct Node));
        New_node->exp=(poly1->exp);
        New_node->coeff=(poly1->coeff)-(poly2->coeff);
        New_node->next=NULL;

        if(head==NULL){
            head=New_node;
        }
        else{
            struct Node* p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=New_node;
        }
        poly1=poly1->next;
        poly2=poly2->next;
    }
    return head;
}

void print(struct Node* head){
    struct Node* p=head;
    while(p->next!=NULL){
        printf("%d x^%d ",p->coeff,p->exp);
        p=p->next;
	if((p->coeff)>0){
            printf("+");
	}
        if(p->next==NULL){
	    printf("%d\n",p->coeff);
        }
    }
}

void freepoly(struct Node* head){
    struct Node* p;
    while(p->next!=NULL){
        p=head;
        head=head->next;
        free(p);
    }
}
int main()
{
    struct Node* poly1=NULL;
    struct Node* poly2=NULL;

    poly1=insert(poly1,3,2);
    poly1=insert(poly1,2,1);
    poly1=insert(poly1,1,0);

    poly2=insert(poly2,1,2);
    poly2=insert(poly2,2,1);
    poly2=insert(poly2,3,0);

    printf("Polynomial 1: ");
    print(poly1);
    printf("Polynomial 2: ");
    print(poly2);

    struct Node* sum=addPolynomials(poly1,poly2);
    printf("After addition  : ");
    print(sum);
    struct Node* difference=subtractPolynomials(poly1,poly2);
    printf("After difference  : ");
    print(difference);

    freepoly(poly1);
    freepoly(poly2);
    freepoly(sum);
    freepoly(difference);
    return 0;
}
