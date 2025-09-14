#include <stdio.h>
#include <stdlib.h>

// Structure definition for a tree node
typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

// Function prototypes
Node* createNode(int key);
Node* insert(Node* root, int key);
int findMax(Node* root);
int findMin(Node* root);
int calculateSum(Node* root);
Node* findLCA(Node* root, int n1, int n2);
void inOrder(Node* root);
void printAVL(Node* root, int space);
void freeMemory(Node* root);
void sumOfChildSubtrees(Node* root, int key);

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to insert a new node in the binary tree
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to calculate the max value in a subtree
int findMax(Node* root) {
    if (root == NULL)
        return -1;
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

// Function to calculate the min value in a subtree
int findMin(Node* root) {
    if (root == NULL)
        return -1;
    while (root->left != NULL)
        root = root->left;
    return root->key;
}

// Function to calculate the sum of all nodes in a subtree
int calculateSum(Node* root) {
    if (root == NULL)
        return 0;
    return root->key + calculateSum(root->left) + calculateSum(root->right);
}

// Function to find Least Common Ancestor (LCA)
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->key == n1 || root->key == n2)
        return root;

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Function for in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to print AVL tree visually
void printAVL(Node* root, int space) {
    const int COUNT = 5;
    if (root == NULL)
        return;

    space += COUNT;

    printAVL(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d", root->key);

    printAVL(root->left, space);
}

// Function to calculate and print the sum of a node's child subtrees
void sumOfChildSubtrees(Node* root, int key) {
    if (root == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (root->key == key) {
        int leftSum = calculateSum(root->left);
        int rightSum = calculateSum(root->right);
        printf("Sum of left subtree: %d\n", leftSum);
        printf("Sum of right subtree: %d\n", rightSum);
        printf("Total sum of child subtrees: %d\n", leftSum + rightSum);
        return;
    }

    if (key < root->key)
        sumOfChildSubtrees(root->left, key);
    else
        sumOfChildSubtrees(root->right, key);
}

// Function to free allocated memory
void freeMemory(Node* root) {
    if (root == NULL)
        return;

    freeMemory(root->left);
    freeMemory(root->right);

    free(root);
}

// Menu-driven program
int main() {
    Node* root = NULL;
    int choice, key, n1, n2;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Calculate max of right subtree\n");
        printf("3. Calculate min of left subtree\n");
        printf("4. Calculate sum of left subtree\n");
        printf("5. Calculate sum of right subtree\n");
        printf("6. Find Least Common Ancestor (LCA)\n");
        printf("7. Print in-order traversal\n");
        printf("8. Print AVL tree visually\n");
        printf("9. Calculate sum of child subtrees for a node\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                if (root == NULL || root->right == NULL)
                    printf("Right subtree is empty.\n");
                else
                    printf("Max of right subtree: %d\n", findMax(root->right));
                break;

            case 3:
                if (root == NULL || root->left == NULL)
                    printf("Left subtree is empty.\n");
                else
                    printf("Min of left subtree: %d\n", findMin(root->left));
                break;

            case 4:
                if (root == NULL || root->left == NULL)
                    printf("Left subtree is empty.\n");
                else
                    printf("Sum of left subtree: %d\n", calculateSum(root->left));
                break;

            case 5:
                if (root == NULL || root->right == NULL)
                    printf("Right subtree is empty.\n");
                else
                    printf("Sum of right subtree: %d\n", calculateSum(root->right));
                break;

            case 6:
                printf("Enter the two nodes to find their LCA: ");
                scanf("%d %d", &n1, &n2);
                Node* lca = findLCA(root, n1, n2);
                if (lca != NULL)
                    printf("LCA of %d and %d is: %d\n", n1, n2, lca->key);
                else
                    printf("LCA not found.\n");
                break;

            case 7:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 8:
                printf("AVL Tree Structure:\n");
                printAVL(root, 0);
                printf("\n");
                break;

            case 9:
                printf("Enter the node to calculate sum of its child subtrees: ");
                scanf("%d", &key);
                sumOfChildSubtrees(root, key);
                break;

            case 10:
                printf("Freeing memory and exiting program...\n");
                freeMemory(root);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}