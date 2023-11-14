#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int value)
{

    if (isFull(q))
    {
        printf("Queue is Full!!\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        printf("Enqued element: %d\n", value);
    }
}

int dequeue(struct circularQueue *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        value = q->arr[q->front];
    }
    return value;
}

void display(struct circularQueue *q)
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
    struct circularQueue q;
    q.size = 5;
    q.front = q.rear = 0; // this space is reserved
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 2);

    display(&q);

    printf("Dequeuing element is: %d\n", dequeue(&q));
    printf("Dequeuing element is: %d\n", dequeue(&q));
    printf("Dequeuing element is: %d\n", dequeue(&q));
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);

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