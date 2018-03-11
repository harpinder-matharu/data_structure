#include "conio.h"
#include "stdio.h"

typedef struct nodetype
{
	int coffi;
	int power;
	struct nodetype *link;
}node;

void main()
{
	
}

node* insert(node *head)
{
	int  cof,pow;
	char yn,c;
	node *ptr=NULL;
	while(yn=='y'||yn=='Y')
	{
		if(head==NULL)
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
			printf("\nEnter cofficient : ");
		}while((scanf("%d%c",&cof,&c)==0||c!='\n')&&printf("\nError! enter only interger."));
		
		do{
			printf("\nEnter power : ");
		}while((scanf("%d%c",&pow,&c)==0||c!='\n')&&printf("\nError! enter only interger."));
	}
	ptr->link = NULL;
	return head;
}
void display(node *head)
{
	node *ptr=head;
	if(head == NULL)
	{
		printf("\nOverflow.");
	}
	else
	{
		printf("\nPolynomial :\n");
		while(ptr!=null)
		{
			printf("%dx^%d ",ptr->coffi,ptr->power);
			ptr = ptr->link;
		}
	}
}
