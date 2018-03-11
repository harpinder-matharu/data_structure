//Conversion of numbers to English words(using stack of linked list).
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#define NULL 0

typedef struct nodetype
{
	char info[6];
	struct nodetype *link;
}node;

node* push(node *head, char *word);
void display(node *head);

void main()
{
	clrscr();
	node *head = NULL;
	long numeric,num;
	int rem,count,i;
	char *words[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	char c;
	do
	{
		printf("\nEnter Integer : ");
		fflush(stdin);
	}
	while((scanf("%ld%c",&numeric,&c)==0||c!='\n')&&printf("\nError! Enter only integer value."));
	num = numeric;
	count=printf("%ld",num);

	for(i=0;i<count;i++)
	{
		rem = num%10;
		head = push(head,words[rem]);
		num=num/10;
	}
	display(head);
	getch();
}

node* push(node *head, char *word)
{
	node *ptr;
	int data;
	ptr = (node *) malloc(sizeof(node));
	ptr ->link = head;
	head = ptr;
	strcpy(ptr->info, word);
	return(head);
}

void display(node *head)
{
	if(head == NULL)
	{
		printf("\nUnderflow.");
		return;
	}

	node *ptr = head;
	printf(" in words : ' ");
	while(ptr!=NULL)
	{
		printf("%s",ptr->info);
		ptr = ptr->link;
		printf(" ");
	}
	printf("'");
}