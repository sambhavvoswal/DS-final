
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arraystackadt.h"
typedef struct student
{
    char usn[11],name[25],dept[6];
    int roll_no,sem;

}STUD;

void printstud(void *s)
{
    STUD *temp;
    if(s)
    {
    temp=(STUD*)s;
    printf("name:%s\n",temp->name);
    printf("usn:%s\n",temp->usn);
    printf("department:%s\n",temp->dept);
    printf("roll no:%d\n",temp->roll_no);
    printf("usn:%d\n",temp->sem);
    } 
}

int main()
{
    STUD *s;
    AST *ph;
    int ch;
   
    ph=(AST*)createstack();
    if(ph)
        printf("Stack created \n");
    else
        printf("Creation failed \n");
    printf("stack of students using array stack ADT\n");

    while(1)
    {
    
        printf("enter choice:\n 1 for push\n 2 to to pop\n 3 to check stack top\n 4 to display stack\n 5 to stack empty\n 6 to stackfull\n 7 to count\n 8 to destroy stack\n 9 to exit\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            s=(STUD*)malloc(sizeof(STUD));
            if (s)
            {
                printf("enter student details:");
                printf("name, usn, department, rollno and semester respectively\n");
                scanf("%s",s->name);
                scanf("%s",s->usn);
                scanf("%s",s->dept);
                scanf("%d",&s->roll_no);
                scanf("%d",&s->sem);

                if(pushstack(ph,s))
                  printf("student pushed successfully\n");
                else 
                  printf("push failed\n");
            }
            else
                printf("stack is full\n"); 
            break;

            case 2:
            s=(STUD*)popstack(ph);
            if(s)
            {
				printf("Data of Student poped : \n");
                printstud(s);
            }
            else
             printf("stack is empty\n");
            break;

            case 3:
            s=(STUD*)stacktop(ph);
            if(s)
            {
                printstud(s);
            }
            else 
             printf("stack is empty\n");
            break;

            case 4:
            displaystack(ph,printstud);
            break;

            case 5:
            if(stackempty(ph))
             printf("stack is empty\n");
            else 
             printf("stack is not empty\n");
            break;

            case 6:
            if(stackfull(ph))
             printf("stack is full\n");
            else 
             printf("stack is not full\n");
            break;

            case 7:
            printf("stack count=%d\n",stackcount(ph));
            break;

            case 8:
            case 9:
            if(destroystack(ph))
             printf("successfull\n");
            else
             printf("unsuccessfull\n");
            return(1);

            default:printf("invalid choice\n");
        }
    }
    return 0;   
}
