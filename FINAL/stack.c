#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stacklladt.h"
void printdata(void *dp)
{
    printf("%d\n",*(int*)dp);
}

int main()
{
    int *dp,ch;
    STACK *head;
    bool result;
    head = createstack();
    if(!head)
    {
       printf("Stack creation failed \n");
       return 1;
    }
    printf("Stack created successfully \n");
    while(1)
    {
        printf("Enter your choice :\n 1 to push element \n 2 to pop element \n 3 to check the top element of the stack \n 4 to check whether the stack is empty  \n 5 to check whether the stack is full \n 6 to know the number of elements in the stack \n 7 to display stack content \n 8 Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                dp = (int*)malloc(sizeof(int));
                if(!dp)
                {
                    printf("Memory allocation failed \n");
                    return 0;
                }
                printf("Enter data to be pushed into the stack\n");
                scanf("%d",dp);
                result = pushstack(head,dp);
                result == 0 ? printf("Failed \n") : printf("Successful \n");
                break;
            }
            case 2:
            {
                dp = (int*)popstack(head);
                if(dp)
                {
                    printf("Poped element : %d\n",*dp);
                    free(dp);
                }
                else
                    printf("Stack is empty \n");
                break;
            }
            case 3:
            {
                dp = (int*)stacktop(head);
                if(dp)
                    printf("Stack top : %d\n",*dp);
                else
                    printf("Stack is empty\n");
                break;
            }
            case 4:
            {
                if(emptystack(head))
                    printf("Stack is empty \n");
                else
                    printf("Stack is not empty \n");
                break;
            }
            case 5:
            {
                if(stackfull())
                    printf("Stack is full \n");
                else
                    printf("Stack is not full \n");
                break;
            }
            case 6:
            {
                printf("Stack count:%d\n",stackcount(head));
                break;
            }
            case 7:
            {
                if(emptystack(head))
                    printf("Stack is empty \n");
                else
                {
                    printf("Stack contains : \n");
                    stackdisplay(head,printdata);
                }
                break;
            }
            case 8:
            {
                if(destroystack(head))
                    printf("Stack is destroyed successfully \n");
                else
                    printf("Stack does not exist \n");
                return 0;
            }
            default :
                printf("Invalid choice \n");
        }    
    }
    return 0;
}

