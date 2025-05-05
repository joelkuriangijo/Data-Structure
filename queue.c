#include <stdio.h>

int que[15], n, front = 0, rear = 0, item;

void enqueue();
void dequeue();
void display();

int main ()
{
    int ch;
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    printf("\n\t\t\t***Queue Operations***\n");

    do
    {
        printf("\nMenu: \n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("\nExiting program...");
            break;
            default:
            printf("\nInvalid choice. Please choose a valid option.");
        }
    } while (ch != 4);
    return 0;
}

void enqueue ()
{
    if(rear==n)
    {
        printf("\nQueue Overflow! Cannot insert more elements.");
    }
    else
    {
        printf("\nEnter an item: ");
        scanf("%d", &item);
        que[rear] = item;
        rear++;
        printf("\nItem Inserted Successfully.");
        display();
    }
}

void dequeue ()
{
    if(front == rear)
    {
        printf("\nQueue Underflow! Cannot delete more elements.");
    }
    else
    {
        printf("\nDeleted item: %d", que[front]);
        front++;
        display();
    }
}

void display ()
{
    int i;
    if(front == rear)
    {
        printf("\nQueue is Empty.\n");
    }
    else
    {
        printf("\nQueue Elements: ");
        for(i = front; i < rear; i++)
        {
            printf("%d ", que[i]);
        }
        printf("\n");
    }
}