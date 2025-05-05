#include <stdio.h>
#include <stdlib.h>
#define size 5

int main() 
{

    int arr[size],R=-1,F=0,count=0,ch,n,i,x;
    printf("\n\t\t\t***Circular Queue Operations***\n");

    for(;;)
    {
        printf("\n1. Add");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                if(count==size)
                {
                    printf("\nQueue is full");
                }
                else
                {
                    printf("\nEnter a number: ");
                    scanf("%d",&n);
                    R=(R+1)%size;
                    arr[R]=n;
                    count=count+1;
                }
                break;
            }
            case 2:
            {
                if(count==0)
                {
                    printf("\nQueue is empty");
                }
                else
                {
                    printf("Number Deleted = %d",arr[F]);
                    F=(F+1)%size;
                    count=count-1;
                }
                break;
            }
            case 3:
            {
                if(count==0)
                {
                    printf("\nQueue is empty");
                }
                else
                {
                    x=F;
                    for(i=1;i<=count;i++)
                    {
                        printf("\n%d",arr[x]);
                        x=(x+1)%size;
                    }
                    printf("\n");
                }
                break;
            }
            case 4:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("\nInvalid choice");
            }
        }
    }
    return 0;
}