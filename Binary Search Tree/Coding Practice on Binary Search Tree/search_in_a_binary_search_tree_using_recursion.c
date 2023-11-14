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

struct Node *searchInBinarySearchTreeUsingRecursion(struct Node *root, int element)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == element)
    {
        return root;
    }
    else if (root->data > element)
    {
        return searchInBinarySearchTreeUsingRecursion(root->left, element);
    }
    else
    {
        return searchInBinarySearchTreeUsingRecursion(root->right, element);
    }
    return 0;
}

int main()
{
    // Constructing the root node using function
    struct Node *p = createNode(50);
    struct Node *p1 = createNode(40);
    struct Node *p2 = createNode(60);
    struct Node *p3 = createNode(20);
    struct Node *p4 = createNode(45);
    struct Node *p5 = createNode(55);
    struct Node *p6 = createNode(70);

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
    p2->left = p5;
    p2->right = p6;

    int element = 70;

    struct Node *ans = searchInBinarySearchTreeUsingRecursion(p, element);
    if (ans != NULL)
    {
        printf("Found: %d ", ans->data);
    }
    else
    {
        printf("Element is not present");
    }

    return 0;
}