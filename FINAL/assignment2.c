#include<stdio.h>
#include<stdlib.h>

int fac(int n)
{
	if(n==0)
		return 1;
	return(n*fac(n-1));
}

int sum(int n)
{
	if(n==0)
		return 0;
	return (n+sum(n-1));
}

int fab(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return( fab(n-1) + fab(n-2) );
}

int main()
{
	int choice,n;
	//int result;
	while(1)
	{
		printf("\nEnter your choice :\n 1 for factorial of number \n 2 for sum till nTH natural number \n 3 for fabbonici series till n number \n And 4 to EXIT\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			{
				printf("Enter a number to get its factorial :\n");
				scanf("%d",&n);
				printf("Factorial of %d = %d",n,fac(n));
				break ;
			}
			case 2:
			{
				printf("Enter a number to get its sum from all previous number :\n");
				scanf("%d",&n);
				printf("Sum of first %d integers = %d",n,sum(n));
				break ;
			}
			case 3:
			{
				printf("Enter a number to get fabbonici series till the nTH term :\n");
				scanf("%d",&n);
				printf("First %d terms of fabbinici series :\n",n);
				for(int i=0;i<n;i++)
				{
			//result = fab(i);
					printf(" %d ",fab(i));
				}
				break ;
			}
			case 4: 
				{
					printf("Exiting......");
					return 0;
				}
			default: printf("Invalid choice\n");
		}
	}
	return 0;
}
