#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void create(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory Allocation Failed\n");
        return;
    }

    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }

    printf("Inserted %d into the Doubly Linked List\n", value);
}

void search(int value)
{
    struct Node *temp = head;
    int pos = 1;
    while(temp != NULL)
    {
        if(temp -> data == value)
        {
            printf("\nValue %d found at position %d\n", value, pos);
            return;
        }
        temp = temp -> next;
        pos++;
    }
    printf("\nValue %d not found in the Doubly Linked List\n", value);
}

void display()
{
    if (head == NULL)
    {
        printf("\nDoubly Linked List is Empty\n");
        return;
    }
    struct Node *temp = head;
    printf("\nDoubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }
    printf("\nNULL\n");
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
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            }

            case 2:
            {
                printf("\nEnter the value to search: ");
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
    }while (choice != 4);

    return 0;
}