#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define NULL 0

typedef struct nodetype
{
	int info;
	char name[20];
	struct nodetype *link;
}node;

node* create(node *head);
node* deletion(node *head);
void traverse(node *head);
void sort(node *head);
void search(node *head);
void search2(node *head);
int clean();

void main()
{
	clrscr();
	int choice;
	char c;
	node *head=NULL;
	printf("Create a list : \n");
	head = create(head);

	while(choice != 7)
	{
		printf("\n****** MENU ******");
		printf("\n1. Insert new node.");
		printf("\n2. Delete node.");
		printf("\n3. Traverse list.");
		printf("\n4. Sort list by numeric.");
		printf("\n5. Sort list by non-numeric.");
		printf("\n6. Search.");
		printf("\n7. Exit.");
		do
		{
			printf("\nEnter your choice(1-6) : ");
			fflush(stdin);
		}
		while((scanf("%d%c",&choice,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

		switch(choice)
		{
			case 1 : head = create(head); break;
			case 2 : head = deletion(head); break;
			case 3 : traverse(head); break;
			case 4 : sort(head); break;
			case 5 : sort2(head); break;
			case 6 : search(head); break;
			case 7 : break;
			default: printf("\nError! please enter valid choice.");
		}
	}
}

node* create(node *head)
{
	node *ptr = head;
	char yn = 'y',c;
	int data;

	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	while( yn == 'y' || yn == 'Y')
	{
		if(ptr == NULL)
		{
			head = (node *) malloc(sizeof(node));
			ptr = head;
		}
		else
		{
			ptr->link = (node *) malloc(sizeof(node));
			ptr = ptr->link;
		}
		printf("\nEnter character info of new node : ");
		scanf("%s",ptr->name);
		do
		{
			printf("\nEnter info of new node : ");
			fflush(stdin);
		}
		while((scanf("%d%c",&data,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

		ptr->info = data;
		printf("Want to continue : (Y or N) : ");
		scanf("%c",&yn);
	}
	ptr->link = NULL;
	return(head);
}
void traverse(node *head)
{
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}

	node *ptr = head;

	printf("\nElements of list : ");
	while(ptr != NULL)
	{
		printf("%d %s",ptr->info,ptr->name);
		ptr = ptr->link;
	}
	printf("\n");
}
node* deletion(node *head)
{
	int item;
	char c;
	node *ptr = head, *prevloc = NULL, *loc;

	if(ptr == NULL)
	{
		printf("\nUnderflow.");
		return head;
	}
	do
	{
		printf("\nEnter info part of node to be deleted : ");
		fflush(stdin);
	}
	while( (scanf("%d%c", &item, &c)==0||c!='\n') &&printf("\nError! Enter only integer value."));

	while(ptr != NULL && ptr->info!=item)
	{
		prevloc = ptr;
		ptr = ptr->link;
	}
	if( item == ptr->info)
	{
		loc = ptr;
	}
	else
	{
		printf("\nItem not fount, exit without deletion.");
		return head;
	}
	if(prevloc == NULL)
	{
			head = ptr->link;
	}
	else
	{
		prevloc->link = loc->link;
	}
	free(loc);
	return head;
}
void sort(node *head)
{
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}

	node *ptr = head, *ptr2 = head;
	int num=0, temp;;

	while(ptr2 != NULL)
	{
		num++;
		ptr2= ptr2->link;
	}

	for(int i=0;i<num-1;i++)
	{
	while(ptr->link != NULL)
	{
		if(ptr->info > ptr->link->info)
		{
			temp = ptr->info;
			ptr->info = ptr->link->info;
			ptr->link->info = temp;
		}
		ptr = ptr->link;
	}ptr = head;
	}
}
void sort2(node *head)
{
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}

	node *ptr = head, *ptr2 = head;
	int num=0, temp;;

	while(ptr2 != NULL)
	{
		num++;
		ptr2= ptr2->link;
	}

	for(int i=0;i<num-1;i++)
	{
	while(ptr->link != NULL)
	{
		if(ptr->info > ptr->link->info)
		{
			temp = ptr->info;
			ptr->info = ptr->link->info;
			ptr->link->info = temp;
		}
		ptr = ptr->link;
	}ptr = head;
	}
}

void search(node *head)
{
	char c;
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}

	node *ptr = head;
	int loc=1, item;
	do
	{
		printf("\nEnter element for search : ");
		fflush(stdin);
	}
	while( (scanf("%d%c", &item, &c)==0||c!='\n')&&printf("\nError! Enter only integer value."));

	while(ptr != NULL && ptr->info != item)
	{
		loc++;
		ptr= ptr->link;
	}
	if(ptr->info == item)
	{
		printf("\nElement at %d location.", loc);
	}
	else
	{
		printf("\nItem not found.");
	}
}
