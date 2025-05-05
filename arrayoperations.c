#include<stdio.h>
int a[20], n, val, i, pos;
void display();  
void insert();   
void del();      
int main() 
{
    int choice;
    printf("\nEnter the size of the array elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    do 
    {
        printf("\n\n--------Menu-----------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("-----------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}

void display() 
{
    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
}
void insert() 
{
    printf("\nEnter the position for the new element: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &val);
    for (i = n-1; i >= pos-1; i--) 
    {
        a[i+1] = a[i];
    }
    a[pos - 1] = val;
    n = n + 1;

    display();
}

void del() 
{
    printf("\nEnter the position of the element to be deleted: ");
    scanf("%d", &pos);

    val = a[pos - 1];
    for (i = pos - 1; i < n - 1; i++) 
    {
        a[i] = a[i + 1];
    }
    n = n - 1;

    printf("\nThe deleted element is = %d", val);
    display();
}