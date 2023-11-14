#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("Elements in the stack are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    else
        return 0;
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

int main()
{
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    linkedListTraversal(top);

    printf("The top most element in the stack is %d\n", stackTop(top));
    printf("The bottom most element in the stack is %d\n", stackBottom(top));

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    return 0;
}