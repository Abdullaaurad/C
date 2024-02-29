#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* InsertNode(struct Node* Tree,int Val){
    if(Tree==NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = Val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(Val<Tree->val){
        Tree->left=InsertNode(Tree->left,Val);
    }
    else{
        Tree->right=InsertNode(Tree->right,Val);
    }
    return Tree;
}

void Inorderprint(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    Inorderprint(Tree->left);
    printf("%d    ",Tree->val);
    Inorderprint(Tree->right);
}

void Preorderprint(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    printf("%d     ",Tree->val);
    Preorderprint(Tree->left);
    Preorderprint(Tree->right);
}

void Postorderprint(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    Postorderprint(Tree->left);
    Postorderprint(Tree->right);
    printf("%d     ",Tree->val);
}

void Maxvalue(struct Node* Tree){
    if(Tree==NULL){
        printf("\nThe Tree is empty");
    }
    else if(Tree->right==NULL){
        printf("\nThe max value is  :%d",Tree->val);
    }
    else{
        Maxvalue(Tree->right);
    }
}

void Minvalue(struct Node* Tree){
    if(Tree==NULL){
        printf("\nThe Tree is empty");
    }
    else if(Tree->left==NULL){
        printf("\nThe min value is  :%d",Tree->val);
    }
    else{
        Maxvalue(Tree->left);
    }
}

int Treesize(struct Node* Tree){
    if(Tree==NULL){
        return 0;
    }
    else{
        return (1+Treesize(Tree->left)+Treesize(Tree->right));
    }
}

int Max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int Height(struct Node* Tree){
    if(Tree==NULL){
        return 0;
    }
    else{
        return (1+Max(Height(Tree->left),Height(Tree->right)));
    }
}

void searchNode(struct Node* Tree, int Val){
    if(Tree==NULL){
        printf("\nthe Value is not in the Tree");
    }
    else if(Val<Tree->val){
        searchNode(Tree->left,Val);
    }
    else if(Val>Tree->val){
        searchNode(Tree->right,Val);
    }
    else{
        printf("\nthe value is in the tree");
    }
}

struct Node* MirrorImage(struct Node* Tree){
    if(Tree==NULL){
        return NULL;
    }
    struct Node* temp=Tree->left;
    Tree->left = Tree->right;
    Tree->right = temp;
    MirrorImage(Tree->left);
    MirrorImage(Tree->right);
    return Tree;
}

int main(){
    struct Node* Tree=NULL;

    printf("How many element in the Tree  :");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Eneter the value of the %d node  :",i+1);
        int value=0;
        scanf("%d",&value);
        Tree=InsertNode(Tree,value);
    }
    printf("\nInorder Traversal  :");
    Inorderprint(Tree);
    printf("\nPreorder Traversal  :");
    Preorderprint(Tree);
    printf("\nPostorder Traversal  :");
    Postorderprint(Tree);

    Maxvalue(Tree);
    Minvalue(Tree);

    printf("\nThe tree size is  :");
    int k=Treesize(Tree);
    printf("%d",k);

    printf("\nThe tree Height is  :");
    int l=Treesize(Tree);
    printf("%d",l);

    searchNode(Tree,4);

    MirrorImage(Tree);
    printf("\nInorder Traversal  :");
    Inorderprint(Tree);
    return 0;
}