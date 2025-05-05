#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory Allocation Failed\n");
        return;
    }
    newNode ->data = value;
    newNode ->next = head;
    head = newNode;
    printf("\nInserted %d at the beginning.\n", value);
}

void search(int value)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("\n%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", value);
}

void displayList()
{
    if(head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d  ->", temp->data);
        temp = temp->next;
    }
    printf("\nNULL\n");
}

int main()
{
    int choice, value;


    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a Node\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the value to be insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            }

            case 2:
            {
                printf("\nEnter the value to be searched: ");
                scanf("%d", &value);
                search(value);
                break;
            }

            case 3:
            {
                displayList();
                break;
            }

            case 4:
            {
                printf("\nExiting...\n");
                break;
            }

            default:
            {
                printf("\nInvalid choice. Please choose a valid option.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
    
}