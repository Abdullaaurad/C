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

struct Node* balance(struct Node* Tree){
    int balance=height(Tree->left)-height(Tree->right);

    if(balance>1 && height(Tree->left->left)>=height(Tree->left->right)){
        return rightRotate(Tree);
    }
    if(balance<-1 && height(Tree->right->right)>=height(Tree->right->left)){
        return leftRotate(Tree);
    }
    if(balance>1 && height(Tree->left->left)<height(Tree->left->right)){
        Tree->left=leftRotate(Tree->left);
        return rightRotate(Tree);
    }
    if(balance>1 && height(Tree->right->right)<height(Tree->right->left)){
        Tree->right=rightRotate(Tree->right);
        return leftRotate(Tree);
    }
    return Tree;
}

struct Node* InsertToAVL(struct Node* Tree,int Val){
    if(Tree==NULL){
        struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
        NewNode->left=NULL;
        NewNode->right=NULL;
        NewNode->data=Val;
        return NewNode;
    }
    else if(Val<Tree->data){
        Tree->left=InsertToAVL(Tree->left,Val);
    }
    else{
        Tree->right=InsertToAVL(Tree->right,Val);
    }

    return balance(Tree);
}

void InorderTraversal(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    InorderTraversal(Tree->left);
    printf("%d   ",Tree->data);
    InorderTraversal(Tree->right);
}

void PreorderTraversal(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    printf("%d   ",Tree->data);
    PreorderTraversal(Tree->left);
    PreorderTraversal(Tree->right);
}

int main(){
    struct Node* Tree=NULL;
    printf("Enter the how many element to eneter  :");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the value for the %d Node  :",i+1);
        int k=0;
        scanf("%d",&k);
        Tree=InsertToAVL(Tree,k);
    }
    
    printf("\nInorder Traversal :");
    InorderTraversal(Tree);
    printf("\nPreorder Traversal :");
    PreorderTraversal(Tree);
    return 0;
}