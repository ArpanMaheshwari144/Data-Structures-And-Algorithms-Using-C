#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!! Cannot push %d to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! Cannot pop from the stack\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

// here i is a position which index starts with 1 from top
int peek(struct stack *ptr, int i)
{
    int arrayIndex = ptr->top - i + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position for the stack\n");
    }
    else
    {
        return ptr->arr[arrayIndex];
    }
}

int stackTop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return sp->arr[sp->top];
    }
}

int stackBottom(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return sp->arr[0];
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    push(sp, 23);
    push(sp, 99);
    push(sp, 100);
    push(sp, 12);

    printf("The top most value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));

    return 0;
}