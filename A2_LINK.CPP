#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define NULL 0

typedef struct nodetype
{
	int info;
	struct nodetype *link;
}node;

node* push(node *head);
node* pop(node *head);
void display(node *head);

void main()
{
	clrscr();
	node *head = NULL;
	int choice;
	char c;
	while(choice != 4)
	{
		printf("\n****** MENU ******");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display");
		printf("\n4. Exit");
		do
		{
			printf("\nEnter your choice : ");
			fflush(stdin);
		}
		while((scanf("%d%c",&choice,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

		switch(choice)
		{
			case 1 : head = push(head);break;
			case 2 : head = pop(head);break;
			case 3 : display(head);break;
			case 4 : break;
			default: printf("\nError! enter valid choice.");
		}
	}
}

node* push(node *head)
{
	node *ptr;
	char yn = 'y',c;
	int data;

	while(yn == 'y' || yn == 'Y')
	{
		ptr = (node *) malloc(sizeof(node));
		ptr ->link = head;
		head = ptr;
		do
		{
			printf("\nEnter info of new node : ");
			fflush(stdin);
		}
		while((scanf("%d%c",&data,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

		ptr->info = data;
		printf("Want to continue (Y or N) : ");
		scanf("%c",&yn);
	}
	return(head);
}

node* pop(node *head)
{
	char yn = 'y';
	while(yn == 'y' || yn == 'Y')
	{
		if(head == NULL)
		{
			printf("\nUnderflow.");
			return head;
		}
		else
		{
			printf("\n%d is poped out of stack.",head->info);
			head = head->link;
			fflush(stdin);
			printf("\nWant to continue (Y or N) : ");
			scanf("%c",&yn);
		}
	}
	return head;
}
void display(node *head)
{
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}
	node *ptr = head;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->info);
		ptr = ptr->link;
	}
}