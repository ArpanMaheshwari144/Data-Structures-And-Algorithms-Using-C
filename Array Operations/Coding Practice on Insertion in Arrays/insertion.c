#include <stdio.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexInsertion(int arr[], int noOfElements, int element, int capacity, int index)
{

    // code for Insertion
    if (noOfElements >= capacity)
    {
        return -1;
    }
    for (int i = noOfElements - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
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
    printf("Before insertion the size of the array is %d\n", noOfElements);
    printf("Before insertion the array is look like this\n");
    display(arr, noOfElements);
    int element, index;
    printf("Enter the element which you want to insert in the array: ");
    scanf("%d", &element);
    printf("On which position you enter the element: ");
    scanf("%d", &index);
    indexInsertion(arr, noOfElements, element, capacity, index);
    noOfElements += 1;
    printf("After insertion the array is look like this\n");
    display(arr, noOfElements);
    printf("After insertion the size of the array is %d\n", noOfElements);

    return 0;
}