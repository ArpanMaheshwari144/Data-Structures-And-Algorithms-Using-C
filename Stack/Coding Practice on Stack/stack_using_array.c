#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; // ye pointer jai jiski madad se hum dynamically memory allocate kar sakte hai array ke liye jo stack ko hold karga
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1; // this represents stack is empty
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // OR

    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); // this is a pointer of a stack
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); // int bcoz in stack we push only integers

    // Pushing an element manually
    // s->arr[0] = 7;
    // s->top++;

    // s->arr[1] = 8;
    // s->top++;

    // s->arr[2] = 9;
    // s->top++;

    // s->arr[3] = 6;
    // s->top++;

    // s->arr[4] = 5;
    // s->top++;

    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    // Check if stack is full
    if (isFull(s))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }

    return 0;
}