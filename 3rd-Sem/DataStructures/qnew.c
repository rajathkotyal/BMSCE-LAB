#include<stdio.h>
#include<stdlib.h>

#define max 10

void insert();
void delete();
void display();


	int choice;
	int q_arr[max];
	int front=-1;
	int rear=-1;
	int x=max;
	int j=1;
	int i;
	
	
int main()
{
	
	while(1)
	{
		printf(" \n 1. Insert Element into Queue");
		printf(" \n 2. Delete Element from Queue");
		printf(" \n 3. Display");
		printf(" \n 4. Quit \n");
		scanf("%d" , &choice);
		
		switch(choice)
		{
			case 1 : 
					insert();
					break;
			case 2 : 
					delete();
					break;
			case 3 :
					 display();
					break;
			case 4 : 
					exit(0);
					break;
			default : 	
					printf("Wrong Choice!! ");
		}
	}
}

void insert()
{	
 if(rear==x)
                printf("\n Queue is Full");
            else
            {
                printf("\n Enter no %d:",j++);
                scanf("%d",&q_arr[rear++]);
            }
	
}

void delete()
 {  if(front==rear)
            {
                printf("\n Queue is empty");
            }
            else
            {
                printf("\n Deleted Element is %d",q_arr[front++]);
                x++;
            }
}
void display()
{
printf("\n Queue Elements are:\n ");
            if(front==rear)
                printf("\n Queue is Empty");
            else
            {
                for(int i=front; i<rear; i++)
                {
                    printf("%d",q_arr[i]);
                    printf("\n");
                }
}}

	
				
