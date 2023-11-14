#include <stdio.h>
#include <stdlib.h> // for malloc

// If the structure is required from the address of the structure, then put *
// "&" Will be required if you want an address from a structure

// this is a abstract data type
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * (sizeof(int)));

    // OR

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * (sizeof(int)));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
}

void setValue(struct myArray *a)
{
    printf("*******Enter the array elements********\n");
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    int size, n;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the number of the elements you want to enter in the array: ");
    scanf("%d", &n);
    createArray(&marks, size, n);
    printf("*******We are running setValue function now*******\n");
    setValue(&marks);
    printf("*******We are running show function now*******\n");
    printf("The array elements you entered are:\n");
    show(&marks);

    return 0;
}