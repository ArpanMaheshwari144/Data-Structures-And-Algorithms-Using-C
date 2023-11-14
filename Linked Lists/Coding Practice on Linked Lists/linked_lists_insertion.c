#include <stdio.h>
#include <stdlib.h>

// Linked list mei agar insertion at the beginning mei to worst case time complexity O(1) hogi
// Linked list mei agar insertion in between the nodes mei to worst case time complexity O(n) hogi
// Linked list mei agar insertion at the end mei to worst case time complexity O(n) hogi
// Linked list mei agar insertion after a given node mei to worst case time complexity O(1) hogi

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

// Case 1 -> Insert At The Beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    // this make a new node dynamically in a heap
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case 2 -> Insert In Between
struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3 -> Insert At The End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4 -> Insert After A Given Node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    // This is dynamic memory allocation which is stored in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("*****Linked list before insertion*****\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertInBetween(head, 56, 1);
    head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, third, 56);
    printf("\n*****Linked list after insertion*****\n");
    linkedListTraversal(head);

    return 0;
}