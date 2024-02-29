#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int val;
    enum Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void inOrderPrint(struct Node* root) {
    if (root == NULL){
        return;
    }
    inOrderPrint(root->left);
    printf("%d-%s\n", root->val, (root->color == RED) ? "Red" : "Black");
    inOrderPrint(root->right);
}

void PreOrderPrint(struct Node* root) {
    if (root == NULL){
        return;
    }
    printf("%d-%s\n", root->val, (root->color == RED) ? "Red" : "Black");
    PreOrderPrint(root->left);
    PreOrderPrint(root->right);
}

struct Node* leftRotate(struct Node* root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return root;
}

struct Node* rightRotate(struct Node* root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;

    return root;
}

struct Node* insertFixup(struct Node* root, struct Node* z) {
//Every contradicton start with the parent and it child being red color
    while (z != NULL && z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {   //checks if the parent of z is the left child of grandparent
            struct Node* y = z->parent->parent->right;   //gets sibling node
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;

            // Case 1: Newly inserted node's uncle is red
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    root = leftRotate(root, z);
                    // Case 2: Newly inserted node's uncle is black and z is a right child
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                root = rightRotate(root, z->parent->parent);
                // Case 3: Newly inserted node's uncle is black and z is a left child
            }
        } else {
            struct Node* y = z->parent->parent->left;  //gets sibling node
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            // Case 1: Newly inserted node's uncle is red    
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    root = rightRotate(root, z);
                    // Case 2: Newly inserted node's uncle is black and z is a left child
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                root = leftRotate(root, z->parent->parent);
                // Case 3: Newly inserted node's uncle is black and z is a right child
            }
        }
    }

    root->color = BLACK;
    return root;
}

struct Node* insertNode(struct Node* root, int val) {
    struct Node* z = createNode(val);
    if (root == NULL) {
        root = z;
    } else {
        struct Node* x = root;
        struct Node* y = NULL;

        while (x != NULL) {
            y = x;
            if (z->val < x->val)
                x = x->left;
            else if (z->val > x->val)
                x = x->right;
            else {
                free(z);
                return root;
            }
        }

        z->parent = y;
        if (z->val < y->val)
            y->left = z;
        else
            y->right = z;
    }
    inOrderPrint(root);
    return insertFixup(root, z);
}



struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteFixup(struct Node* root, struct Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            struct Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                root = leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    root = rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                root = leftRotate(root, x->parent);
                x = root;
            }
        } else {
            struct Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                root = rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    root = leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                root = rightRotate(root, x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->val){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val){
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            // Case: No children or one child
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        } else {
            // Case: Node with two children, find successor
            struct Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == NULL)
        return root;

    // Fix the Red-Black tree properties
    if (root->color == BLACK) {
        // Determine which child of root is being deleted
        struct Node* x = (root->left == NULL || root->right == NULL) ? root : root->right;
        root = deleteFixup(root, x);
    }
    return root;
}


int main() {
    struct Node* root = NULL;

    printf("How many elements in the Red-Black tree: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i + 1);
        int value;
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInOrder Traversal: \n");
    inOrderPrint(root);
    printf("\nPreOrder Traversal: \n");
    PreOrderPrint(root);

    printf("How many elements to remove: ");
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Enter the value of node %d: ", i + 1);
        int value;
        scanf("%d", &value);
        root = deleteNode(root, value);
    }

    printf("\nInOrder Traversal: \n");
    inOrderPrint(root);
    printf("\nPreOrder Traversal: \n");
    PreOrderPrint(root);

    return 0;
}
