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

void insertInABinarySearchTree(struct Node *root, int elementToBeInserted)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (elementToBeInserted == root->data)
        {
            printf("\nCannot insert %d, it is already present in binary search tree ", elementToBeInserted);
            return;
        }
        else if (elementToBeInserted < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *ptr = createNode(elementToBeInserted);
    if (elementToBeInserted < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
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

    int elementToBeInserted = 16;

    printf("Before inserting the new element: ");
    inOrderTraversal(p);
    insertInABinarySearchTree(p, elementToBeInserted);
    printf("\nAfter inserting the new element: ");
    inOrderTraversal(p);

    return 0;
}