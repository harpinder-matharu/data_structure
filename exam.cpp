#include "conio.h"
#include "stdio.h"
#include "process.h"
#include "stdlib.h"

typedef struct nodetype
{
	int info;
	struct nodetype *link;
}node;

node* create(node *head);
node* insertEnd(node *head);
node* deleteN(node *head);
node* reverse(node *head);
void traverse(node *head);

int main()
{
	int choice = 0;
	char c;
	node *head = NULL;
	head = create(head);
	
	while(choice != 5)	
	{
		printf("\n****** MENU ******");
		printf("\n1. Insert a node.");
		printf("\n2. Delete a node.");
		printf("\n3. Reverse a list.");
		printf("\n4. Traverse a list.");
		printf("\n5. Exit.");
		do{
			printf("\nEnter your choice : ");
			fflush(stdin);
		}while((scanf("%d%c",&choice,&c)==0||c!='\n')&&printf("Error! enter only integer value."));
		
		switch(choice)
		{
			case 1 : head = insertEnd(head);
					 break;
			case 2 : head = deleteN(head);
					 break;
			case 3 : head = reverse(head);
					 break;
			case 4 : traverse(head);
					 break;
			case 5 : exit;
					 break;
			default: printf("Error! Enter valid choice.");
		}
	}
	return 0;
}

node* create(node *head)
{
	int data;
	char yn='y', c;
	node *ptr = head;
	
	while(yn=='Y' || yn=='y')
	{
		if(ptr == NULL)
		{
			head = (node *)malloc(sizeof(node));
			ptr = head;
		}
		else
		{
			ptr->link = (node *)malloc(sizeof(node));
			ptr = ptr->link;
		}
		do{
			printf("\nEnter info of new node : ");
			fflush(stdin);
		}while((scanf("%d%c",&data,&c)==0||c!='\n')&&printf("\nError! Enter only integer value"));
		ptr->info = data;
		
		printf("Want to continue ? (Y or N) : ");
		scanf("%c",&yn);
	}
	ptr->link = NULL;
	return head;
}

node* insertEnd(node *head)
{
	int data;
	char c;
	node *ptr = head;
	
	if(ptr == NULL)
	{
		head = (node *)malloc(sizeof(node));
		ptr = head;
	}
	else
	{
		while(ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = (node *)malloc(sizeof(node));
		ptr = ptr->link;
	}
	do{
		printf("\nEnter info of new node : ");
		fflush(stdin);
	}while((scanf("%d%c",&data,&c)==0||c!='\n')&&printf("\nError! Enter only integer value"));
	ptr->info = data;
	
	ptr->link = NULL;
	return head;
}

node* deleteN(node *head)
{
	int data;
	char c;
	node *ptr = head, *prevloc = NULL, *loc;
	
	if(ptr == NULL)
	{
		printf("\nUnderflow.");
		return head;
	}
	do{
		printf("\nEnter info part of node to be deleted : ");
		fflush(stdin);
	}while((scanf("%d%c",&data,&c)==0||c!='\n')&&printf("\nError! Enter only integer value"));
	
	while(ptr->link!=NULL && ptr->info!= data)
	{
		prevloc = ptr;
		ptr = ptr->link;
	}
	if(ptr->info == data)
	{
		loc = ptr;
	}
	else
	{
		printf("\nItem not found, Exit without deletion.");
		return head;
	}
	if(prevloc==NULL)
	{
		head = loc->link;
	}
	else
	{
		prevloc->link = loc->link;
	}
	free(loc);
	return head;
}

node* reverse(node *head)
{
	int flag=0;
	node* prev   = NULL;
    node* ptr = head;
    node* next;
    while (ptr != NULL)
    {
    	//printf("\n\nIteration.");
        next  = ptr->link;  
        //printf("\n\nNEXT = %d, ",ptr->link->info);
        ptr->link = prev;
        if(flag ==0)
        {
        	printf("%d k ptr->link = null , ",ptr->info);
        	flag=1;
    	}
        else
        printf("%d k ptr->link = %d , ",ptr->info,prev->info);
        prev = ptr;
        printf("prev = %d, ",ptr->info);
        ptr = next;
        printf("ptr = %d.\n",next->info);
    }
    head = prev;
    return head;
}

void traverse(node *head)
{
	node *ptr = head;
	if(ptr == NULL)
	{
		printf("Underflow!");
		return;
	}
	printf("\nElements of list are : ");
	while(ptr != NULL)
	{
		printf("%d ",ptr->info);
		ptr = ptr->link;
	}
}

