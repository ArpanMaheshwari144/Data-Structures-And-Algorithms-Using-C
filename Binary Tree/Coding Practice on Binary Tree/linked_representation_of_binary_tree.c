#include <stdio.h>
#include <stdlib.h> // for malloc

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

int main()
{
    // Constructing the root node using function
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}