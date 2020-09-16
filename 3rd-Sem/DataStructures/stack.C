#include<stdio.h>
#include<conio.h>
#define SIZE 10
int top=-1,stack[SIZE];
void push(int x)
{
   if(top>=SIZE-1)
      printf("Error:Stack Full\n");
   else
      {
top=top+1;
stack[top]=x;
      }
}

void pop()
{
   if(top==-1)
      printf("Error:Stack Empty\n");
   else
      top=top-1;
}

void print()
{
int i;
  if(top==-1)
    printf("Stack Empty\n");
  else
    {
      printf("Stack: ");
      for(i=0;i<=top;i++)
printf("%d ",stack[i]);
    }
}

void main()
{
  int choice,a;
  clrscr();
  do
  {
    printf("\n1)Push\n2)Pop\n3)Print\n4)Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("Enter the element: ");
      scanf("%d",&a);
      push(a);
      break;
      case 2:pop();
    break;
      case 3:print();
    break;
      case 4:exit(0);
    break;
      default:printf("your choice doesnot exist\n");
     }
     }while(choice!=4);
  getch();
}

