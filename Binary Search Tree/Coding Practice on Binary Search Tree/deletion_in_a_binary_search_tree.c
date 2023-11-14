#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    // Creating a node pointer
    struct Node *temp;

    // Allocating memory in the heap
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Set the data
    temp->data = data;

    // Set the left and right children to NULL
    temp->left = NULL;
    temp->right = NULL;

    // Finally return the created node
    return temp;
};

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Inorder Predecessor -> left subtree ka rightmost child
struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int elementToBeDeleted)
{
    struct Node *inOrderPred;

    // Base Condition
    if (root == NULL)
    {
        return NULL;
    }

    // We reach to that node which we want to delete
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Search for the node to be deleted
    if (elementToBeDeleted < root->data)
    {
        root->left = deleteNode(root->left, elementToBeDeleted);
    }
    else if (elementToBeDeleted > root->data)
    {
        root->right = deleteNode(root->right, elementToBeDeleted);
    }
    // Deletion strategy when the node is found
    else
    {
        inOrderPred = inOrderPredecessor(root);
        root->data = inOrderPred->data;
        root->left = deleteNode(root->left, inOrderPred->data);
    }
    return root;
}

int main()
{
    // Constructing the root node using function
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    if (p == NULL)
    {
        printf("There is no elements in a binary search tree");
        exit(0);
    }

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int elementToBeDeleted = 6;

    printf("Before deleteing the element: ");
    inOrderTraversal(p);
    deleteNode(p, elementToBeDeleted);
    printf("\nAfter deleteing the element: ");
    inOrderTraversal(p);

    return 0;
}