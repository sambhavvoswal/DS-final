
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listLLADT.h"

typedef struct COURSE 
{
  char code[10];
  char title[25];
  int credit;
  int l,t,p;
  int cie,see;
  char type[2];
}course;

void printlist(void *dp)
{
  course *t=(course*)dp;
  printf("course code %s\n",t->code);
  printf("course title %s\n",t->title);
  printf("course credit %d\n",t->credit);
  printf("l:t:p=%d %d %d\n",t->l,t->t,t->p);
  printf("cie = %d, see = %d\n",t->cie,t->see);
  printf("course type=%s\n",t->type);
}

bool compare(void *p,void *q)
{
  course *t,*d;
  t=(course*)p;
  d=(course*)q;

  if(!strcmp(t->code,d->code))
    return (true);
  return (false);
}

int main()
{
  char pkey[10];
  int ch;
  course *c;
  list *p;
  bool res;
  NODE *pred;
  p=createlist();
  if(!p)
    {
        printf("failed to createlist\n");
        return(1);
     }
  else
  {
    printf("list created successfully\n");
  }

    while(1)
    {
      printf("enter your choice:\n 1 to insert \n 2 to delete \n 3 to retrieve list \n 4 to search\n 5 to display\n 6 to list full \n 7 to list epmty\n 8 to list count\n 9 to exit\n");
      scanf("%d",&ch);

    switch(ch)
    {
      case 1:
      printf("enter your choice:\n 1 in beginning \n 2 in middle\n 3 in end\n");
      scanf("%d",&ch);

      switch(ch)
      {
        case 1:
        pred=NULL;
        break;

        case 2:
        printf("enter the course code after which new node is to be inserted\n");
        scanf("%s",pkey);

        pred=searchlist(p,pkey,compare);
        if(!pred)
         printf("search failed\n");
        break;

        case 3:
        pred=p->head;
        while(pred->next)
         pred=pred->next;
        break;
        default:break;
      }
      if(ch==2 && pred==NULL)
       break;
      c=(course*)malloc(sizeof(course));
      if(!c)
      {
        printf("list is full\n");
        break;
      }
      printf("enter course details\n");
      printf("course code:\n");
      scanf("%s",c->code);
      printf("course title:\n");
      scanf("%s",c->title);
      printf("course credit:\n");
      scanf("%d",&c->credit);
      printf("enter l:t:p respectively\n");
      scanf("%d %d %d",&c->l,&c->t,&c->p);
      printf("cie and see marks respectively\n");
      scanf("%d %d",&c->cie,&c->see);
      printf("course type:\n");
      scanf("%s",c->type);
      res=insertion(p,pred,c);
      if(res)
       printf("successfull\n");
      else 
       printf("unsuccessfull\n");
      break;

      case 2:
      printf("enter your choice: \n 1 in beginning \n 2 in midle\n 3 in end\n");
      scanf("%d",&ch);
      NODE *t;

      switch(ch)
        {
          case 1:
          pred=NULL;
          break;

          case 2:
          printf("enter the course code to delete the course\n");
          scanf("%s",pkey);

          //NODE *t;
          pred=NULL;
          t=p->head;

          while(t!=NULL && strcmp(pkey,((course*)t->dp)->code))
            {
              pred=t;
              t=t->next;

            }
          case 3:
          pred=NULL;
          //NODE *t;
          t = p->head;
          
          while(t->next)
            {
              pred=t;
              t=t->next;

            }
          break;
          default:printf("inalid choice\n");
          break;
        }
      if(ch==2 && t==NULL)
      {
        printf("course is not found\n");
        break;

      }
      c=(course*)deletion(p,pred);
      printlist(c);
      free(c);
      break;

      case 3:
      printf("enter the course code to retrieve the course\n"); 
      scanf("%s",pkey);
      c=(course*)retrievelist(p,pkey,compare);
      printlist(c);
      break;

      case 4:
      printf("enter the course code to search the course\n");
      scanf("%s",pkey);
      pred=(NODE*)searchlist(p,pkey,compare);
      if(pred)
      {
        printf("course is found\n");
        printlist(pred->dp);

      }
     else
        printf("course is not found\n");
      break;

      case 5:if(emptylist(p))
      {
        printf("list is empty\n");

      }
        else 
        displaylist(p,printlist);
      break;
      case 6:if(fulllist(p))
               printf("list is full\n");
             else 
        printf("list is not full\n");
      break;
      case 7:if(emptylist(p))
              printf("list is empty\n");
            else
             printf("list is not empty\n");
            break;
      case 8:printf("count of list is %d\n",countlist(p));
             break;
      case 9:
      if(destroylist(p))
         printf("destroyed\n");
      else 
        printf("unsuccessfull\n");
      return 0;
      default:printf("invalid choice\n");
    }
}
return 0;
}




