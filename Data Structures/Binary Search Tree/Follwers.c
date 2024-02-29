#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[50];
    int Age;
    int followers;
    struct Node* left;
    struct Node* right;
};

int max(int a,int b){
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
    return (1+max(Height(Tree->left),Height(Tree->right)));
}

struct Node* leftRotate(struct Node* Tree){
    struct Node* x=Tree->right;
    struct Node* y=x->left;

    x->left=Tree;
    Tree->right=y;
    return x;
}

struct Node* rightRotate(struct Node* Tree){
    struct Node* x=Tree->left;
    struct Node* y=x->right;

    x->right=Tree;
    Tree->left=y;
    return x;
}

int getBalance(struct Node* Tree) {
    if (Tree == NULL)
        return 0;
    return Height(Tree->left) - Height(Tree->right);
}

struct Node* balanceNode(struct Node* node) {
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* InsertNode(struct Node* Tree,char User[],int Val,int age){
    if(Tree==NULL){
        struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
        NewNode->followers=Val;
        strcpy(NewNode->name,User);
        NewNode->Age=age;
        NewNode->left=NULL;
        NewNode->right=NULL;
        return NewNode;
    }
    else if(Val<Tree->followers){
        Tree->left=InsertNode(Tree->left,User,Val,age);
    }
    else{
        Tree->right=InsertNode(Tree->right,User,Val,age);
    }
    
    return balanceNode(Tree);
}

void InorderTraversal(struct Node* Tree){
    if(Tree==NULL){
        return;
    }
    InorderTraversal(Tree->left);
    printf("\nUserName :%s    ",Tree->name);
    printf("Age :%d    ",Tree->Age);
    printf("Followers :%d    ",Tree->followers);
    InorderTraversal(Tree->right);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int Val) {
    if (root == NULL)
        return root;

    if (Val < root->followers)
        root->left = deleteNode(root->left, Val);
    else if (Val > root->followers)
        root->right = deleteNode(root->right, Val);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->followers = temp->followers;
            root->Age = temp->Age;
            strcpy(root->name, temp->name);
            root->right = deleteNode(root->right, temp->followers);
        }
    }
    if(root==NULL){
        return root;
    }
    return balanceNode(root);
}
int main(){
    struct Node* Tree=NULL;
    Tree=InsertNode(Tree,"Alice",1000,25);
    Tree=InsertNode(Tree,"Bob",500,30);
    Tree=InsertNode(Tree,"Charlie",750,22);
    Tree=InsertNode(Tree,"David",800,28);
    Tree=InsertNode(Tree,"Eve",1200,29);

    printf("\n\t\tInOrderTraversal  ");
    InorderTraversal(Tree);

    Tree=deleteNode(Tree,750);
    printf("\n\t\tInOrderTraversal  ");
    InorderTraversal(Tree);

    return 0;
}