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
		printf("No memory allocatipon\n");
		exit(0);
	}
}
NODE insert_front(NODE head,int item)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE insert_end(NODE head,int item)
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

int main()
{
	NODE head=NULL;
	int option,ele;
	while(1)
	{
		printf("1.Insert front element \n2.Insert end element\n3.Display\n4.Exit\n\n");
		printf("Enter option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("\nEnter element to be inserted\n");
				scanf("%d",&ele);
				head=insert_front(head,ele);
				break;
			case 2: printf("\nEnter element to be inserted\n");
				scanf("%d",&ele);
				head=insert_end(head,ele);
				break;
			
			case 3:printf("\nElements in list are\n\n");
				display(head);
				break;
			case 4:
				exit(0);
				
		}
	}
	return 0;
}

/*bmsce@bmsce-Precision-T1700:~$ cd Desktop
bmsce@bmsce-Precision-T1700:~/Desktop$ gcc linkedList.c
bmsce@bmsce-Precision-T1700:~/Desktop$ ./a.out
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
1

Enter element to be inserted
10
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
1

Enter element to be inserted
20
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
1

Enter element to be inserted
30
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
3

Elements in list are

30
20
10
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
2

Enter element to be inserted
40
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
3

Elements in list are

30
20
10
40
1.Insert front element 
2.Insert end element
3.Display
4.Exit

Enter option
4
bmsce@bmsce-Precision-T1700:~/Desktop$ ^C
bmsce@bmsce-Precision-T1700:~/Desktop$ 
*/
