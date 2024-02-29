 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* rightRotate(struct Node* Tree){
    struct Node* x=Tree->left;
    struct Node* y=x->right;

    x->right=Tree;
    Tree->left=y;

    return x;
}

struct Node* leftRotate(struct Node* Tree){
    struct Node* x=Tree->right;
    struct Node* y=x->left;

    x->left=Tree;
    Tree->right=y;

    return x;
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int height(struct Node* Tree){
    if(Tree==NULL){
        return 0;
    }
    else{
        return (1+max(height(Tree->left),height(Tree->right)));
    }
}

struct Node* InsertToDSW(struct Node* Tree,int Val){
    if(Tree==NULL){
        struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
        NewNode->left=NULL;
        NewNode->right=NULL;
        NewNode->data=Val;
        return NewNode;
    }
    else if(Val<Tree->data){
        Tree->left=InsertToDSW(Tree->left,Val);
    }
    else{
        Tree->right=InsertToDSW(Tree->right,Val);
    }
    return Tree;
}

void InOrderTraversal(struct Node* Tree){
    if(Tree!=NULL){
        InOrderTraversal(Tree->left);
        printf("%d   ",Tree->data);
        InOrderTraversal(Tree->right);
    }
}

void PreorderTraversal(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    printf("%d   ",Tree->data);
    PreorderTraversal(Tree->left);
    PreorderTraversal(Tree->right);
}

struct Node* BackBone(struct Node* Root){
    int i=0;
    struct Node* ptr=Root;
    struct Node* start=ptr;
    while(ptr!=NULL){
        if(ptr->left!=NULL){
            printf("\nRotating right %d",ptr->data);
            ptr=rightRotate(ptr);
            if(i==0){
                start=ptr;
            }
        }
        else if(ptr->right!=NULL){
            printf("\nNext right node %d",ptr->data);
            ptr=ptr->right;
            i++;
        }
        else{
            return start;
        }
    }
}

int main(){
    struct Node* Tree=NULL;
    printf("Enter the how many element to enter  :");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the value for the %d Node  :",i+1);
        int k=0;
        scanf("%d",&k);
        Tree=InsertToDSW(Tree,k);
    }
    
    printf("\nInOrder Traversal :");
    InOrderTraversal(Tree);
    printf("\nPreorder Traversal :");
    PreorderTraversal(Tree);

    Tree=BackBone(Tree);

    printf("\nInOrder Traversal :");
    InOrderTraversal(Tree);
    printf("\nPreorder Traversal :");
    PreorderTraversal(Tree);
    return 0;
}