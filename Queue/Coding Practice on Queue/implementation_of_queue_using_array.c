#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("This Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        printf("Enqued element: %d\n", value);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void display(struct queue *q)
{
    printf("Elements in queue are: ");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    display(&q);

    printf("Dequeuing element is: %d\n", dequeue(&q));
    printf("Dequeuing element is: %d\n", dequeue(&q));

    display(&q);

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }

    if (isFull(&q))
    {
        printf("Queue is Full\n");
    }

    return 0;
}