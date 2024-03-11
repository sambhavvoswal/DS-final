#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    void *dp;
    struct node *next;
}NODE;
typedef struct stack
{
    NODE *top;
    int count;
}STACK;

STACK* createstack()
{
    STACK *s;
    s=(STACK*)malloc(sizeof(STACK));
    if(s)
    {
        s->top=NULL;
        s->count=0;
    }
    return s;
}

bool pushstack(STACK *head,void *dpin)
{
    NODE *pnew;
    pnew=(NODE*)malloc(sizeof(NODE));
    if(pnew)
    {
        pnew->dp = dpin;
        // pnew->next = head->dp;
        pnew->next = head->top;
        head->top = pnew;
        head->count++;
        return(true);
    }
    return(false);
}

void* popstack(STACK *head)
{
    if(!head->count)
        return NULL;
    void *dpout;
    NODE *pout;
    pout=head->top;
    head->top=pout->next;
    head->count--;
    dpout=pout->dp;
    free(pout);
    return(dpout);
}


void* stacktop(STACK *head)
{
    if(!head->count)
        return NULL;
    return(head->top->dp);
}

bool emptystack(STACK *head)
{
    if(!head->count)
        return(true);
    return(false);
}

bool stackfull()
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp)
    {
        free(temp);
        return (false);
    }
    return (true);
}


int stackcount(STACK *head)
{
   return(head->count); 
}

void stackdisplay(STACK *head,void(*ps)(void *))
{
    NODE *temp;
    for(temp=head->top;temp!=NULL;temp=temp->next)
    {
        ps(temp->dp);
    }
}


bool destroystack(STACK *head)
{
    if(!head)
        return false;
    void *dpout;
    NODE *temp,*deletenode;
    for(temp=head->top;temp!=NULL;)
    {
        deletenode=temp;
        temp=temp->next;
        dpout=deletenode->dp;
        free(deletenode);
        free(dpout);
    }
    free(head);
    return(true);

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
