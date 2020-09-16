#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory allocation not found \n\n");
		exit(0);
	}
}
NODE enqueue(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	q->next=NULL;
	
	if(head==NULL)
		{
			
			return q;
		}
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
	return head;
	
}
NODE dequeue(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("List is empty!! \n\n");
	}
	printf("Deleted element is : %d \n\n",p->data);
	head=p->next;
	free(p);
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty!! \n\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	NODE p,q,head=NULL;
	p=getnode();
	q=getnode();
	int option,ele,pos,value;
	while(1)
	{
		printf("1.Insert an Element \n2.Delete an Element \n3.Display\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				head=enqueue(head,ele);
				break;
			case 2:head=dequeue(head);
				break;
			case 3:printf("Elements in list are : \n");
				display(head);
				break;
			case 4:exit(0);
				break;
			default :printf("Invalid choice!!");
				break;
				
		}
	}
	return 0;
}

