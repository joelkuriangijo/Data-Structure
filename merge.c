#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) 
{
    int i, j;
    
    for (i = 0; i < size1; i++) 
    {
        merged[i] = arr1[i];
    }
    
    for (j = 0; j < size2; j++) 
    {
        merged[i + j] = arr2[j];
    }
}

int main() 
{
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    
    int arr1[size1];
    
    printf("Enter %d elements for the first array:\n", size1);
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    
    int arr2[size2];
    
    printf("Enter %d elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) 
    {
        scanf("%d", &arr2[i]);
    }
    int merged[size1 + size2];
    mergeArrays(arr1, size1, arr2, size2, merged);

    printf("Merged array:\n");
    for (int i = 0; i < size1 + size2; i++) 
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}