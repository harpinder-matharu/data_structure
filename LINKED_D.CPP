//doubly linked list.

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef struct nodetype
{	
	struct nodetype *prev;
	int info;
	struct nodetype *next;
}node;

node *head = NULL, *tail = NULL;

void create();
void insert();
void deletion();
void traverse();
void sort();
void search();

int main()
{
	int choice;
	char c;
	printf("Create a list : \n");
	create();

	while(choice != 6)
	{
		printf("\n****** MENU ******");
		printf("\n1. Insert new node.");
		printf("\n2. Delete node.");
		printf("\n3. Traverse list.");
		printf("\n4. Sort list.");
		printf("\n5. Search list.");
		printf("\n6. Exit.");
		do
		{
			printf("\nEnter your choice(1-6) : ");
			fflush(stdin);
		}
		while((scanf("%d%c",&choice,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

		switch(choice)
		{
			case 1 : insert(); break;
			case 2 : deletion(); break;
			case 3 : traverse(); break;
			case 4 : sort(); break;
			case 5 : search(); break;
			case 6 : break;
			default: printf("\nError! please enter valid choice.");
		}
	}
	return 0;
}

void create()
{
	int data;
	char c, yn = 'y';
	node *ptr;
	
	while(yn == 'y' || yn == 'Y') 
	{
		if(head == NULL)
		{
			head = (node *)malloc(sizeof(node));
			head->prev = NULL;
			ptr = head;
		}
		else
		{
			ptr->next = (node *)malloc(sizeof(node));
			ptr->next->prev = ptr;
			ptr = ptr->next;
		}
	}
}
void insert()
void deletion()
void traverse()
void sort()
void search()
