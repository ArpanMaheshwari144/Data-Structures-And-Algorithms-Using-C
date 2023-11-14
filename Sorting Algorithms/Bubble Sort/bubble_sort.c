#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of pass
    {
        printf("Pass: %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // for comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // for number of pass
    {
        isSorted = 1;
        printf("Pass: %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // for comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting ");
    printArray(arr, n); // Print the array before sorting

    // printf("=============================================\n");
    // printf("Sorting by Simple Bubble Sort\n");
    // bubbleSort(arr, n); // Function to sort the array
    // printf("After sorting by Simple Bubble Sort ");
    // printArray(arr, n); // Print the array after sorting

    printf("===========================================\n");
    printf("Sorting by Naive Bubble Sort\n");
    bubbleSortAdaptive(arr, n); // Function to sort the array
    printf("After sorting by Naive Bubble Sort ");
    printArray(arr, n); // Print the array after sorting

    return 0;
}