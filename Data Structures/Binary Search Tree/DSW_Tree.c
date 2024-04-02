 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* rightRotate(struct Node* Tree){
    if (Tree == NULL || Tree->left == NULL) {
        return Tree;  // No rotation possible, return original tree
    }

    struct Node* x = Tree->left;
    Tree->left = x->right;
    if (x->right != NULL) {
        x->right->left = NULL;  // Set left child's left pointer to NULL after rotation
    }
    x->right = Tree;

    return x;
}

struct Node* leftRotate(struct Node* Tree){
    struct Node* x=Tree->right;
    Tree->right=x->left;
    x->left=Tree;
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


void PreorderTraversal(struct Node* Tree) {
    if (Tree != NULL) {
        printf("%d ", Tree->data);
        PreorderTraversal(Tree->left);
        PreorderTraversal(Tree->right);
    }
}

struct Node* BackBone(struct Node* Root){
    int i=0;
    struct Node* ptr=Root;
    struct Node* start=ptr;
    while(ptr!=NULL){
        printf("\n\n\n");
        printf("Start is :%d\n",start->data);
        PreorderTraversal(ptr);
        printf("\n\n\n");
        if(ptr->left!=NULL){
            printf("\nRotating right %d ",ptr->data);
            ptr=rightRotate(ptr);
            printf("\nAfter Rotation ptr is %d",ptr->data);
            printf("\nAfter Rotation ptr right is %d",ptr->right->data);
            if(ptr->right->left!=NULL){
                printf("\nAfter Rotation ptr right left is %d",ptr->right->left->data);
            }
            if(i==0){
                start=ptr;
            }
        }
        else if(ptr->right!=NULL){
            printf("\nNext right node from %d is %d ",ptr->data,ptr->right->data);
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