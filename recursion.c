#include <stdio.h>


int factorial(int n) 
{
    if (n == 0 || n == 1)
    {
    return 1;
    }
    return n * factorial(n - 1);
}


int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main()
{
    int ch, num, i;
    do 
    {
        printf("\nMenu:\n\n");
        printf("1. Find Factorial\n");
        printf("2. Generate Fibonacci Series\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);


        switch (ch)
        {
            case 1:
            {
                printf("Enter a number to find factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d = %d\n", num, factorial(num));
                break;
            }

            case 2:
            {
                printf("Enter the number of terms in the Fibonacci Series: ");
                scanf("%d", &num);
                printf("Fibonacci Series up to %d terms: ", num);
                for (i = 0; i < num; i++)
                {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\nExiting the program...\n");
                break;
            }

            default:
            {
                printf("Invalid choice. Please choose a valid option.\n");
                break;
            }
        }
    }
    while (ch != 3);

    return 0;
}