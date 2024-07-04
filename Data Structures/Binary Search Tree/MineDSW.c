#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* rightRotate(struct Node* Tree) {
    if (Tree != NULL && Tree->left != NULL) {
        struct Node* parent = Tree;
        struct Node* leftson = parent->left;
        struct Node* grandson = leftson->right;
        leftson->right = parent;
        parent->left = grandson;
        return leftson;
    }
    return Tree;
}

struct Node* leftRotate(struct Node* Tree) {
    if (Tree != NULL && Tree->right != NULL) {
        struct Node* parent = Tree;
        struct Node* rightson = parent->right;
        struct Node* grandson = rightson->left;
        rightson->left = parent;
        parent->right = grandson;
        return rightson;
    }
    return Tree;
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
        printf("%d ",Tree->data);
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

void PostorderTraversal(struct Node* Tree) {
    if (Tree != NULL) {
        PostorderTraversal(Tree->left);
        PostorderTraversal(Tree->right);
        printf("%d ", Tree->data);
    }
}

struct Node* BstToVine(struct Node* root){
    while (root->left != NULL){
        root = rightRotate(root);
    }
    struct Node* current = root->right;
    struct Node* previous = root;
    while (current != NULL){
        while (current->left != NULL){
            current = rightRotate(current);
            previous->right = current;
        }
        previous = current;
        current = current->right;
    }
    return root;
}

void compress(struct Node** root, int times){
    struct Node* head = NULL;
    struct Node* prev = NULL;
    struct Node* node = *root;
    for (int i = 0; i < times; i++){
        node = leftRotate(node);
        if (prev != NULL){
            prev->right = node;
        }
        else{
            head = node;
        }
        prev = node;
        node = node->right;
        if (node == NULL){
            break;
        }
    }
    *root = head;
}

void DSWAlgorithm(struct Node** _root, const int total_node){
    struct Node* root = *_root;
    root = BstToVine(root);
    int level = (int)floor(log2f((float)total_node));
    int bottom = total_node - ((1 << level) - 1);

    compress(&root, bottom);

    for (int i = ((1 << level) - 1) / 2; i > 0; i /= 2){
        compress(&root, i);
    }

    *_root = root;
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
    printf("\nPostorder Traversal :");
    PostorderTraversal(Tree);

    DSWAlgorithm(&Tree,n); // Changed Tree to &Tree to pass the address

    printf("\nInOrder Traversal :");
    InOrderTraversal(Tree);
    printf("\nPreorder Traversal :");
    PreorderTraversal(Tree);
    printf("\nPostorder Traversal :");
    PostorderTraversal(Tree);
    
    return 0;
}
