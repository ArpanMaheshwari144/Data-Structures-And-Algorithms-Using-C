#include <stdio.h>
#include <stdlib.h>

//Represent a node of binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//Represent the root of binary tree
struct node *root = NULL;

//createNode() will create a new node
struct node *createNode(int data)
{
    //Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    //Assign data to newNode, set left and right children to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int calculateSum(struct node *temp)
{
    int sum, sumLeft, sumRight;
    sum = sumRight = sumLeft = 0;

    //Check whether tree is empty
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else
    {
        //Calculate the sum of nodes present in left subtree
        if (temp->left != NULL)
            sumLeft = calculateSum(temp->left);

        //Calculate the sum of nodes present in right subtree
        if (temp->right != NULL)
            sumRight = calculateSum(temp->right);

        //Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data
        sum = temp->data + sumLeft + sumRight;
        return sum;
    }
}

int main()
{
    //Add nodes to the binary tree
    root = createNode(5);
    root->left = createNode(2);
    root->right = createNode(9);
    root->left->left = createNode(1);
    root->right->left = createNode(8);
    root->right->right = createNode(6);

    //Display the sum of all the nodes in the given binary tree
    printf("Sum of all nodes of binary tree: %d", calculateSum(root));
    return 0;
}