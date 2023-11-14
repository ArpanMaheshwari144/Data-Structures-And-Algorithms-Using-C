#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;

    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;

        // Loop for each pass
        printf("Pass: %d\n", i);
        while (j >= 0 && A[j] > key) // this loop prints the elements in increasing order
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
    printf("Sorting by Insertion Sort\n");
    insertionSort(arr, n);
    printf("After sorting by Insertion Sort ");
    printArray(arr, n);

    return 0;
}