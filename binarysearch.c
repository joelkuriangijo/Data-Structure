#include <stdio.h>

int binarySearch(int arr[], int n, int tar) 
{
    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == tar) 
        {
            return mid;
        }

        if (arr[mid] < tar) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main() 
{
    int n, tar, r;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &tar);

    r = binarySearch(arr, n, tar);

    if (r != -1) 
    {
        printf("Element %d found at index: %d\n", tar, r+1);
    } 
    else 
    {
        printf("Element %d not found in the array.\n", tar);
    }

    return 0;
}