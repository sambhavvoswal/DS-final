#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int i,r;
}c;

void* int_sum(void *n1,void*n2)
{
	int *s = (int*)malloc(sizeof(int));
	*s = *((int*)n1) + *((int*)n2);
	return s;
}

void* float_sum(void *n1, void *n2)
{
	float *s = (float*)malloc(sizeof(float));
	*s = *((float*)n1) + *((float*)n2);
	return s;
}

void* complex_sum(void *n1,void *n2)
{
	c *s = (c*)malloc(sizeof(c));
	s->r=((c*)n1)->r + ((c*)n2)->r;
	s->i=((c*)n1)->i + ((c*)n2)->i;
	return s;
}

void* sum_two_nos(void *n1, void *n2 , void *(*fb)(void *n1,void *n2))
{
	return fb(n1,n2);
}

void *getfun(int choice)
{
	switch(choice)
	{
		case 1:return &int_sum;
		case 2:return &float_sum;
		case 3:return &complex_sum;
		default: return NULL;
	}
}

int main()
{
	void*(*fb)(void*,void*);
	int choice ;
	void *n1;
	void *n2;
	while(1)
	{
		printf("\nEnter your choice :\n 1 for integer addition \n 2 for floating point addition \n 3 for complex addition\n And 4 to EXIT\n");
		scanf("%d",&choice);
		fb = getfun(choice);
		switch(choice)
		{
			case 1:
			{
				n1 = (int*)malloc(sizeof(int));
				n2 = (int*)malloc(sizeof(int));
				printf("Enter two integer numbers :\n");
				scanf("%d %d",(int*)n1 , (int*)n2);
				printf("Sum of %d & %d = %d",*((int*)n1),*((int*)n2),*((int*)sum_two_nos(n1,n2,fb)));
				break ;
			}
			case 2:
			{
				n1 = (float*)malloc(sizeof(float));
				n2 = (float*)malloc(sizeof(float));
				printf("Enter two floating point numbers :\n");
				scanf("%f %f",(float*)n1 , (float*)n2);
				printf("Sum of %0.2f & %0.2f = %0.2f",*((float*)n1),*((float*)n2),*((float*)sum_two_nos(n1,n2,fb)));
				break ;
			}
			case 3:
			{
				n1 = (c*)malloc(sizeof(c));
				n2 = (c*)malloc(sizeof(c));
				printf("Enter  first complax number numbers :\n");
				printf("Real Part :\n");
				scanf("%d",&((c*)n1)->r);
				printf("Imaginary Part :\n");
				scanf("%d",&((c*)n1)->i);
				
				printf("Enter  second complax number numbers :\n");
				printf("Real Part :\n");
				scanf("%d",&((c*)n2)->r);
				printf("Imaginary Part :\n");
				scanf("%d",&((c*)n2)->i);
				c *s=sum_two_nos(n1,n2,fb);
				printf("\nSum of COmplex number :\n Real part :%d \n Imaginary part: %d\n",s->r,s->i);
				free(s);
				break ;
				case 4: 
				{
					printf("Exiting......");
					return 0;
				}
				default: printf("Invalid choice\n");
			}
			free(n1);
			free(n2);
		}
	}
	return 0;
}
