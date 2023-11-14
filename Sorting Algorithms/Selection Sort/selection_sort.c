#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n)
{
    int indexOfMin, temp;

    // Loop for passes
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass: %d\n", i + 1);
        indexOfMin = i;

        // Loop for each pass
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap of arr[i] and arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
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
    printArray(arr, n);
    printf("Sorting by Selection Sort\n");
    selectionSort(arr, n);
    printf("After sorting by Selection Sort ");
    printArray(arr, n);

    return 0;
}