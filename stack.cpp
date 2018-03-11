#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define MAX 5

typedef struct
{
	int s[MAX];
	int top;
}stack;

void create(stack*);
void push(stack*);
void pop(stack*);
void display(stack*);
void peek(stack*);

int main()
{
	stack s1;
	unsigned int choice;
	int item, flag=0;
	char c;
	
	create(&s1);
	while(choice!=5)
	{
		if(flag == 1)
		{
			printf("\nEnter for more...");
			getch();
			system("cls");
		}
		
		printf("\nMENU \n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
		do{
			printf("\nEnter your choice : ");
			fflush(stdin);
		}while((scanf("%u%c",&choice,&c)==0||c!='\n'||choice>5)&&printf("\nError! Enter valid choice."));
		
		switch(choice)
		{
			case 1: push(&s1);break;
			case 2: pop(&s1);break;
			case 3: peek(&s1);break;
			case 4: display(&s1);break;
		}
		flag=1;
	}
	return 0;
}

void create(stack* sp)
{
	sp->top = -1;
}
void push(stack* sp)
{
	if(sp->top == MAX-1)
		printf("\nOverflow : Stack is full.");
	else
	{
		int item;
		printf("\nEnter element to push : ");
		scanf("%d",&item);
		sp->top++;
		sp->s[sp->top] = item;
	}
}
void pop(stack* sp) 
{
	if(sp->top == -1)	
		printf("\nUnderflow : Stack is Empty");
	else
	{
		printf("\nElemnet popped : %d",sp->s[sp->top]);
		sp->top--;
	}
}
void display(stack* sp)
{
	if(sp->top == -1)	
		printf("\nUnderflow : Stack is Empty");
	else
	{
		printf("\nCotent of stack : ");
		for(int i=0; i <= sp->top; i++)
		{
			printf("%d\t",sp->s[i]);
		}
	}
}
void peek(stack* sp)
{
	if(sp->top == -1)	
		printf("\nUnderflow : Stack is Empty");
	else
		printf("\nItem on peek : %d",sp->s[sp->top]);
}
