#include <stdio.h>
#define MAX 15
int stack[MAX], top = -1, item;
void push();
void pop();
void display();

int main() 
{
    printf("\n\t\t\t***STACK OPERATION***\n\n");
    int ch;

    do
    {
        printf("\nMenu: ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
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
    }
    while (ch != 4);
    return 0;
}

void push()
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter an item: ");
        scanf("%d", &item);
        stack[top]=item;
        top++;
        printf("\nItem Inserted Successfully: %d\n", item);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("\nItem Deleted Successfully: %d\n", item);
            
    }    
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nStack Elements: \n");
        for(i=top; i>=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}