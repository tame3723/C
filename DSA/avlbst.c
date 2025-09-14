#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL Tree
typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

// Function to get the height of a node
int height(Node *node) {
    return node == NULL ? 0 : node->height;
}

// Function to create a new node
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Function to perform right rotation
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Function to perform left rotation
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Get balance factor of a node
int getBalance(Node *node) {
    return node == NULL ? 0 : height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function for in-order traversal
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to print AVL tree visually
void printAVL(Node *root, int space) {
    const int COUNT = 5;  // Space between levels
    
    if (root == NULL) return;
    
    // Increase distance between levels
    space += COUNT;
    
    // Process right child first (top of output)
    printAVL(root->right, space);
    
    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d(%d)", root->key, root->height);
    
    // Process left child
    printAVL(root->left, space);
}

// Function to find the level of a node
int findLevel(Node* root, int key, int level) {
    if (root == NULL) return -1;
    if (root->key == key) return level;

    int left = findLevel(root->left, key, level + 1);
    if (left != -1) return left;

    return findLevel(root->right, key, level + 1);
}
void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


// Menu driver program
int main() {
    Node *root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a node\n");
        printf("2. Delete a node\n");
        printf("3. Traverse in-order\n");
        printf("4. Traverse post-order\n");  // New option
        printf("5. Traverse pre-order\n");   // New option
        printf("6. Get height of the tree\n");
        printf("7. Find level of a node and balance factor\n");
        printf("8. View the tree structure\n");
        printf("9. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 7:
                printf("Enter the value to find its level and balance factor: ");
                scanf("%d", &key);
                int level = findLevel(root, key, 1);
                if (level == -1) {
                    printf("Node not found in the tree.\n");
                } else {
                    printf("Level of node %d: %d\n", key, level);
                    printf("Balance factor of node %d: %d\n", key, getBalance(root));
                }
                break;
            case 8:
                printf("AVL Tree structure:\n");
                printAVL(root, 0);
                printf("\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
        

    return 0;
}