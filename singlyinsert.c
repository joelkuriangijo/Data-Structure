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
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;
    }
    printf ("Inserted %d at the end.\n", value);
}

void insertAtPosition(int value, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        int i;
        for(i=1;temp !=NULL && i<position-1;i++)
        temp = temp->next;

        if (temp == NULL)
        {
            printf("Position is out of range\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at position %d.\n", value, position);
}

void displayList()
{
    if (head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d  ->", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, position, value;

    do
    {
        printf("\n\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
            {
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            }
            case 2:
            {
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            }
            case 3:
            {
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            }
            case 4:
            {
                displayList();
                break;
            }
            case 5:
            {
                printf("\n\nExiting program...\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Please choose a valid option.\n");
                break;
            }
        }
    }
    while (choice != 5);


    return 0;
}