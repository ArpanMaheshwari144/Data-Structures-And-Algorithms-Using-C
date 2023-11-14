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

void display(struct stack *ptr)
{
    int i;

    if (ptr->top == -1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack is...\n");
        for (i = ptr->top; i >= 0; --i)
            printf("%d\n", ptr->arr[i]);
    }
}

int main()
{
    // this will give space in a heap area where our stack is stored
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    printf("Before pushing the ");

    display(sp);
    push(sp, 5);
    push(sp, 10);
    push(sp, 15);
    push(sp, 20);
    push(sp, 25);

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    printf("After pushing the ");
    display(sp);

    printf("Before pop the ");
    display(sp);
    printf("Before pop, Top is: %d\n", sp->top);
    printf("Popped %d from the stack\n", pop(sp)); // Last In, First Out
    printf("After pop the ");
    display(sp);
    printf("After pop, Top is: %d\n", sp->top);

    return 0;
}