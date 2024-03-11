#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayqueueadt.h"

void printdata(void* dp)
{
	printf("%s\n",(char*)dp);
}

int main()
{
	char *str;
	aqueue *q;
	int ch;
	bool res;
	
	q=createqueue();
	{
		if(q)
		  printf("queue is created\n");
		else 
		{
			printf("queue is not created\n");
			return 1;
		}
	}

    while(1)
    {
		printf("enter your choice: \n 1 to enqueue\n 2 to dequeue\n 3 to retrieve front\n 4 to retrieve rear\n 5 to queuefull\n 6 to queueempty\n 7 to queue count\n 8 to displayqueue\n 9 to exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				str=(char*)calloc(q->size,sizeof(char));
				printf("enter a string\n");
				scanf("%s",str);
				res=enqueue(q,str);
				if(res)
				 printf("enqueued succefully\n");
				else
				 printf("unsuccessfull\n");
				break;
			
		
		case 2:
			str=(char*)dequeue(q);
			if(str)
			{
				printf("deleted string is : %s\n",str);
				free(str);
				
			}
			else
			{
				printf("queue is empty\n");
				
			}
			break;
		
		case 3:
			str=(char*)retrievefront(q);
			if(str)
			 printf("element at front : %s\n",str);
			else 
			 printf("queue is empty\n");
			break; 
		
		case 4:
			str=(char*)retrieverear(q);
			if(str)
			 printf("element at rear : %s\n",str);
			else 
			 printf("queue is empty\n");
			break;
			
		case 5:
			if(qfull(q))
			 printf("queue is full\n");
			else 
			 printf("queue is not full\n");
			break;
		
		case 6:
			if(qempty(q))
			 printf("queue is empty\n");
			else
			 printf("queue is not epmty\n");
			break;
			
		case 7:
			printf("number of queue elements : %d",qcount(q));
			printf("\n");
			break;
		
		case 8:
			displayq(q,printdata);
			printf("\n");
			
			break;
		
		case 9:
			destroyq(q);
			printf("program terminated\n");
			return 1;
			
		
		default:printf("invalid choice\n");
		}
	}
return 0;
}

