#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indexDeletion(int arr[], int noOfElements, int index)
{
    // code for Deletion
    if (index >= noOfElements)
    {
        printf("Deletion is not possible\n");
        exit(0);
    }
    else
    {
        for (int i = index; i < noOfElements - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
}

int main()
{
    int capacity, noOfElements;
    printf("Enter the capacity of the array: ");
    scanf("%d", &capacity);
    printf("Enter the number of elements you want to store in the array: ");
    scanf("%d", &noOfElements);
    int arr[capacity];
    printf("Enter the array elements\n");
    for (int i = 0; i < noOfElements; i++)
    {
        printf("Enter the element whose index is %d:", i);
        scanf("%d", &arr[i]);
    }
    printf("Before deletion the size of the array is %d\n", noOfElements);
    printf("Before deletion the array is look like this\n");
    display(arr, noOfElements);
    int index;
    printf("Enter the index of element you want to delete in the array: ");
    scanf("%d", &index);
    indexDeletion(arr, noOfElements, index);
    noOfElements -= 1;
    printf("After deletion the array is look like this\n");
    display(arr, noOfElements);
    printf("After deletion the size of the array is %d\n", noOfElements);
    return 0;
}