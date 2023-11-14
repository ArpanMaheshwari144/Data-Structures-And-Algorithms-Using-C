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

int isBinarySearchTree(struct Node *root)
{
    // if we do not use static so it will make prev = NULL in every recursive call
    /*static varibles jab hum kisi function mei banate hai or us static variable par hum recursion use kar
    rahe hai to us variable ki value alag-alag calls ke liye different nhi hogi */
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        // same function is call for left side on a tree
        if (!isBinarySearchTree(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root; // changing the prev pointer
        return isBinarySearchTree(root->right);
    }
    else
    {
        return 1;
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

    inOrderTraversal(p);
    printf("\n");

    int result = isBinarySearchTree(p);
    if (result == 1)
    {
        printf("This tree is a binary search tree");
    }
    else
    {
        printf("This tree is not a binary search tree");
    }

    return 0;
}