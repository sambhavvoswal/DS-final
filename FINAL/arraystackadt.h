
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct arraystrack
{
    void** st;
    int top,count;
    int size;
}AST;

AST* createstack()
{
    AST *head;
    head=(AST*)malloc(sizeof(AST));
    if(head)
    {
        printf("enter the stack size:\n");
        scanf("%d",&head->size);
        head->st=(void**)calloc(head->size,sizeof(void*));
        if(head->st)
        {
            head->top=-1;
            head->count=0;
        }
        else
        {
            free(head);
            return(NULL);

        }
    }
      return(head);
}

bool stackempty(AST *h)
{
    if(h->top==-1)
     return(true);
    return(false); 
}

bool stackfull(AST *h)
{
    if(h->top==h->size)
     return(true);
    return(false); 
}
bool pushstack(AST *h,void *dpin)
{
    if(stackfull(h))
     return false;
    h->top++;
    h->st[h->top]=dpin;
    h->count++;
    return (true);
}

void* popstack(AST *h)
{
    void *dpout;
    if(stackempty(h))
     return NULL;
    dpout=h->st[h->top];
    (h->top)--;
    h->count--;
    return(dpout);
}

void* stacktop(AST *h)
{
    if(stackempty(h))
     return(NULL);
    return(h->st[h->top]); 
}


int stackcount(AST *h)
{
    return(h->count);
}

void displaystack(AST *h,void(*pd)(void*))
{
    int i;
    if(stackempty(h))
    {
        printf("stack is empty\n");
        return;
    }
    for(i=h->top;i>=0;i--)
     pd(h->st[i]);
}

bool destroystack(AST *head)
{
    if(head)
    {
        while(head->count)
        {
            free(head->st[head->top]);
            (head->top)--;
            (head->count)--;
        }
        free(head->st);
        free(head);
        return(true);
    }
    return(false);   
}


