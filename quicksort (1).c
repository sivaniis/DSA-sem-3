#include <stdio.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int start = low;  
    int end = high;

    while (start < end) 
    {
        while (start < end && arr[end] > pivot) 
	{
            end--;
        }
        while (start < end && arr[start] <= pivot) 
	{
            start++;
        }

        if (start < end) 
	{
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);
    return end;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter the size of array:"); 
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

