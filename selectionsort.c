#include <stdio.h>

void selectionSort(int arr[], int n) 
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) 
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() 
{
    int arr[50],n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}