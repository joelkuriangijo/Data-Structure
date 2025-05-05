#include<stdio.h>
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
        return i;
        }
    }
    return -1;
}

int main()
{
    int n, x, r, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array:\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the number to search for: ");
    scanf("%d", &x);

    r = linearSearch(arr, n, x);

    if(r != -1)
    {
        printf("Element %d is present at index %d\n", x, r);
    }
    else
        {
            printf("Element is not present in array\n");
        }
    return 0;
}

