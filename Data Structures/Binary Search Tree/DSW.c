#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void TreeNodeLeftRotate(struct TreeNode **node);
static void TreeNodeRightRotate(struct TreeNode **node);
static struct TreeNode *BstToVine(struct TreeNode *root);
static void compress(struct TreeNode **root, int times);
void DSWAlgorithm(struct TreeNode **_root, const int total_node);

void displayInOrder(struct TreeNode *root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%d ", root->data);
        displayInOrder(root->right);
    }
}

void displayPreOrder(struct TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}

void displayPostOrder(struct TreeNode *root) {
    if (root != NULL) {
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        printf("%d ", root->data);
    }
}

struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void TreeNodeLeftRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->right != NULL)
        {
            struct TreeNode *rightson = parent->right;
            struct TreeNode *grandson = rightson->left;
            rightson->left = parent;
            parent->right = grandson;
            *node = rightson;
        }
    }
}

void TreeNodeRightRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->left != NULL)
        {
            struct TreeNode *leftson = parent->left;
            struct TreeNode *grandson = leftson->right;
            leftson->right = parent;
            parent->left = grandson;
            *node = leftson;
        }
    }
}

struct TreeNode *BstToVine(struct TreeNode *root)
{
    while (root->left != NULL)
    {
        TreeNodeRightRotate(&root);
    }
    struct TreeNode *current = root->right;
    struct TreeNode *previous = root;
    while (current != NULL)
    {
        while (current->left != NULL)
        {
            TreeNodeRightRotate(&current);
            previous->right = current;
        }
        previous = current;
        current = current->right;
    }
    return root;
}

void compress(struct TreeNode **root, int times)
{
    struct TreeNode *head = NULL, *prev = NULL;
    struct TreeNode *node = *root;
    for (int i = 0; i < times; i++)
    {
        TreeNodeLeftRotate(&node);
        if (prev != NULL)
            prev->right = node;
        else
            head = node;
        prev = node;
        node = node->right;
        if (node == NULL)
            break;
    }
    *root = head;
}

void DSWAlgorithm(struct TreeNode **_root, const int total_node)
{
    struct TreeNode *root = *_root;
    root = BstToVine(root);
    int level = (int)floor(log2f((float)total_node));
    int bottom = total_node - ((1 << level) - 1);

    compress(&root, bottom);

    for (int i = ((1 << level) - 1) / 2; i > 0; i /= 2)
    {
        compress(&root, i);
    }

    *_root = root;
}

int main() {
    struct TreeNode *root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 8);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 5);
    insertNode(root, 4);
    insertNode(root, 3);

    // Display the unbalanced tree
    printf("\t\tUnbalanced Binary Search Tree:\n");
    printf("InOrder Traversal =");
    displayInOrder(root);
    printf("\nPreOrder Traversal =");
    displayPreOrder(root);
    printf("\nPostOrder Traversal =");
    displayPostOrder(root);
    printf("\n");

    // Balance the tree using DSW algorithm
    DSWAlgorithm(&root, 6);

    // Display the balanced tree
    printf("\t\t\nBalanced Binary Search Tree (DSW Algorithm):\n");
    printf("InOrder Traversal =");
    displayInOrder(root);
    printf("\nPreOrder Traversal =");
    displayPreOrder(root);
    printf("\nPostOrder Traversal =");
    displayPostOrder(root);
    printf("\n");

    return 0;
}