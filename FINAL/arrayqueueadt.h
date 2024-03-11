#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int front,rear;
	int count,size;
	void **pq;
}aqueue;

aqueue *createqueue()
{
	aqueue *q;
	q=(aqueue*)malloc(sizeof(aqueue));
	if(q)
	{
		printf("enter size of array\n");
		scanf("%d",&q->size);
		
		q->rear=-1;
		q->front=-1;
		q->count=0;
		
		q->pq=(void**)calloc(q->size,sizeof(void*));
		
			if(!q->pq)
			{
			  free(q);
			  return NULL;
		    }
		
	}
	return(q);
}
	
	bool qfull(aqueue *q)
	{
		if(q->count==(q->size))
		 return (true);
		return (false);
	}
	
	bool qempty(aqueue *q)
	{
		if(q->count==0)
		 return (true);
		return (false);
	}
	  
	
	bool enqueue(aqueue *q,void *datain)
	{
		if(qfull(q))
		 return false;
		if(qempty(q))
	    {
			q->front=0;
			q->rear=0;
		}
		else
		{
			
		q->rear=(q->rear+1)%q->size;
	   }
	   q->pq[q->rear]=datain;
	   q->count++;
	   return true;
    }
 	 
	void* dequeue(aqueue *q)
	{
		void* dataout;
		if(qempty(q))
		 return NULL;
		dataout=q->pq[q->front];
		q->front=(q->front+1)%q->size;
		q->count--;
		if(q->count==0)
		{
			q->front=-1;
			q->rear=-1;
		}
		
		return (dataout);
	}
	
	void* retrievefront(aqueue *q)
	{
		if(qempty(q))
		 return NULL;
		return(q->pq[q->front]);
	}
	
	void* retrieverear(aqueue *q)
	{
		if(qempty(q))
		 return NULL;
		return(q->pq[q->rear]);
	}
	
   int qcount(aqueue *q)
   {
	   return(q->count);
   }
   void displayq(aqueue *q,void(*fp)(void*))
   {
	   int temp;
	   if(qempty(q))
	   {
		   printf("queue is empty\n");
	   }
	   else
	   {
		   printf("queue contents are:\n");
		   for(temp=q->front;temp!=q->rear;temp=(temp+1)%q->size)
		    fp(q->pq[temp]);
		   
		   fp(q->pq[temp]);
	   }
   }
   
   void destroyq(aqueue *q)
   {
	   int temp=q->front,i=0;
	   if(q)
	   {
		while(i<q->count)
		   {
			   free(q->pq[temp]);
			   temp=(temp+1)%q->size;
			   i++;
		   }
		   free(q->pq);
		   free(q);
	   }
	   
   }

