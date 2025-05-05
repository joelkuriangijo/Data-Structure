#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node* left;
    struct Node* right;
};


struct Node* root = NULL;

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void addNode(int value)
{
    struct Node* newNode = createNode(value);
    if (root == NULL)
    {
        root = newNode;
        printf("Node having value %d is added as root\n", value);
        return;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (value > current->info)
        {
            current = current->right;
        }
        else if (value < current->info)
        {
            current = current->left;
        }
        else
        {
            printf("\nNode having value %d already exists\n", value);
            free(newNode);
            return;
        }
    }

    if (value > parent->info)
    {
        parent->right = newNode;
    }
    else
    {
        parent->left = newNode;
    }
    printf("Node having value %d is added\n", value);
}


void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d] ", root->info);
        inorder(root->right);
    }
}


void preorder(struct Node* root)
{
    if (root != NULL)
    {
        printf("[%d] ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->info);
    }
}



int main()
{
    int ch, value;

    do 
    {
        printf("\n1. Add Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                addNode(value);
                break;
            }

            case 2:
            {
                if (root == NULL)
                {
                    printf("\nTree is empty\n");
                }
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            }

            case 3:
            {
                if (root == NULL)
                {
                    printf("\nTree is empty\n");
                }
                else
                {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            }

            case 4:
            {
                if (root == NULL)
                {
                    printf("\nTree is empty\n");
                }
                else
                {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            }

            case 5:
            {
                printf("\nExiting the program...\n");
                break;
            }

            default:
            {
                printf("\nInvalid choice. Please choose a valid option.\n");
                break;
            }
        }
    }
    while (ch != 5);

    return 0;
}