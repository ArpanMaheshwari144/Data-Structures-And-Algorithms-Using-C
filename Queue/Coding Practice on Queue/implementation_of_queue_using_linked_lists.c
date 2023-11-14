#include <stdio.h>
#include <stdlib.h>

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("This Queue is Empty\n");
        printf("Elements in the Linked Lists are: %d\n", ptr);
    }
    else
    {
        printf("*****Elements in the Linked Lists are*****\n");
        while (ptr != NULL)
        {
            printf("Element are: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void enqueue(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("This Queue is Full\n");
    }
    else
    {
        n->data = value;
        n->next = NULL;
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    int value = -1;
    struct Node *ptr = front;
    if (front == NULL)
    {
        printf("This Queue is Empty\n");
    }
    else
    {
        front = front->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}

int main()
{
    enqueue(34);
    enqueue(4);
    enqueue(3);
    enqueue(40);

    linkedListTraversal(front);

    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());

    linkedListTraversal(front);

    return 0;
}