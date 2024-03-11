
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  void* dp;
  struct node *next;
}NODE;

typedef struct LIST
{
  NODE* head;
  int count;
}list;

list* createlist()
{
  list *p;
  p=(list*)malloc(sizeof(list));
  if(p)
  {
    p->head=NULL;
    p->count=0;
  }
  return(p);
}

bool insertion(list *p,NODE *pred,void *din)
{
  NODE* pnew;
  pnew=(NODE*)malloc(sizeof(NODE));
  pnew->dp=din;
  if(pred==NULL)
  {
    pnew->next=p->head;
    p->head=pnew;
  }
  else
  {
    pnew->next=pred->next;
    pred->next=pnew;
  }
  p->count++;
  return(true);
}

void* deletion(list *p,NODE *pred)
{
  NODE *dnode;
  void *dout;
  if(!p->head)
    return NULL;
  else if(!pred)
  {
    dnode=p->head;
    p->head=dnode->next;
  }
  else
  {
    dnode=pred->next;
    pred->next=dnode->next;
  }
  dout=dnode->dp;
  free(dnode);
  p->count--;
  return(dout);
}

NODE* searchlist(list *p,void *pkey,bool(*comp)(void*,void*))
{
  NODE *temp;

  temp=p->head;
  while(temp!=NULL)
  {
    if(comp(temp->dp,pkey))
     return temp;
    temp=temp->next;
  }
  return NULL;
}

void* retrievelist(list* p,void *pkey,bool(*comp)(void*,void*))
{
   NODE *temp;
   temp=searchlist(p,pkey,comp);
   if(temp)
    return(temp->dp);
     return NULL;
}

int countlist(list *p)
{
  return(p->count);
}

bool emptylist(list *p)
{
  if(p->count==0)
   return (true);
  return(false);  
}

bool fulllist(list *p)
{
  NODE *n;
  n=(NODE*)malloc(sizeof(NODE));
  if(n)
  {
    free(n);
    return(false);
  }
  return(true);
}

void displaylist(list *p,void(*fp)(void*))
{
  NODE *t;
  t=p->head;
  while(t!=NULL)
  {
    fp(t->dp);
    t=t->next;
  }
}

bool destroylist(list *p)
 {
   NODE *t,*d;
   if(!p)
    return(false);
   t=p->head;
   while(t)
   {
     d=t;
     t=t->next;
     free(d->dp);
     free(d);
   }
   free(p);
   return(true);
 }


