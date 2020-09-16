//Stacks using Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node* Node;

Node push(int ele, Node top)
{
    if (top == NULL)
    {
        top =(Node)malloc(sizeof(struct node));
        top->next = NULL;
        top->data = ele;
	return top;
    }
    else
    {
        Node temp =(Node)malloc(sizeof(struct node));
        temp->next = top;
        temp->data = ele;
        top = temp;
	return top;
    }
}
void display(Node top)
{
    Node t = top;

    if (t == NULL)
    {
        printf("Stack is empty!!");
        return;
    }
    printf(" The Elements present in the stack are:\n");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
 }
Node pop(Node top)
{
    Node t = top;

    if (t == NULL)
    {
        printf("\nStack underflow!!");
        return top;
    }
    else
        t = t->next;
    printf("\n The Popped element is : %d", top->data);
    free(top);
    top = t;
    return top;
}

void main()
{
	int no, ch, e;
	Node top = NULL;
	while (1)
	{
		printf("\n 1.Push an Element \n 2.Pop an Element \n 3.Display\n 4.Exit");
		printf("\n Enter a choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:printf(" Enter element to be pushed : ");
			       scanf("%d", &no);
			       top = push(no, top);
			       break;
			case 2:top = pop(top);
			       break;
			case 3:display(top);
			       break;
			case 4:  exit(0);
			default :printf("Invalid Input");
				 break;
		}
	}	
}
