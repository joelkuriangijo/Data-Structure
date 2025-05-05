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

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted node from the beginning.\n");
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        struct Node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Deleted node from the end.\n");
}

void deleteFromPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    if (position == 1)
    {
        head = head->next;
        free(temp);
        printf("Deleted node from the position %d.\n", position);
        return;
    }

    struct Node *prev = NULL;
    int i;
    for(i=1; temp !=NULL && i<position; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
    {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted node from the position %d.\n", position);
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
    printf("NULL\n");
}

int main()
{
    int choice, position, value;

    do
    {
        printf("\n\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Specified Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
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
                deleteFromBeginning();
                break;
            }
            case 3:
            {
                deleteFromEnd();
                break;
            }
            case 4:
            {
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            }
            case 5:
            {
                displayList();
                break;
            }
            case 6:
            {
                printf("\n\nExiting program...\n\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Please choose a valid option.\n");
                break;
            }
        }
    }
    while (choice != 6);


    return 0;
}