#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return;
    }
    newNode ->data = value;
    newNode ->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        head -> next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
    }
    printf("Inserted %d into the Circular Linked List.\n", value);
}

void search(int value)
{
    if (head == NULL)
    {
        printf("\nCircular Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;

    do 
    {
        if (temp -> data == value)
        {
            printf("\n%d is found at position %d.\n", value, pos);
            return;
        }
        temp = temp -> next;
        pos++;
    } while (temp != head);

    printf("Value %d is not found in the Circular Linked List.\n", value);
}

void display()
{
    if (head == NULL)
    {
        printf("\nCircular Linked List is Empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nCircular Linked List: ");
    do
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    } while (temp != head);
    printf("(head)\n");
}

int main()
{
    int choice, value;
    do
    {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                create(value);
                break;
            }

            case 2:
            {
                printf("Enter value to be search: ");
                scanf("%d", &value);
                search(value);
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                printf("\nExiting...\n");
                break;
            }

            default:
            {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}