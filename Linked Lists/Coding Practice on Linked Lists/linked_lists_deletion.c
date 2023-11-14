#include <stdio.h>
#include <stdlib.h>

// Linked list mei agar Deleting the first node mei to worst case time complexity O(1) hogi
// Linked list mei agar Deleting in between the nodes mei to worst case time complexity O(n) hogi
// Linked list mei agar Deleting the last element mei to worst case time complexity O(n) hogi
// Linked list mei agar Deleting the element with a given value(first node with that value) mei to worst case time complexity O(1) hogi

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Elements in linked lists are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting in between the nodes
struct Node *deleteInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the element with a given value
struct Node *deleteTheValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next; // p ka next usko point karega jisko q ka next point kar raha hai
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("*****Linked list before deletion*****\n");
    linkedListTraversal(head);
    // head = deleteAtFirst(head);
    // head = deleteInBetween(head, 3);
    // head = deleteAtLast(head);
    head = deleteTheValue(head, 3);
    printf("\n*****Linked list after deletion*****\n");
    linkedListTraversal(head);

    return 0;
}