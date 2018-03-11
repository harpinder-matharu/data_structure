#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAX 10

void display(int arr[], int *top);
void push(int arr[], int *top);
void pop(int arr[], int *top);
int clean();

int main(int argc, char *argv)
{
	clrscr();
	int arr[MAX];
	int choice, top = -1;
	char c;

	while(choice != 4)
	{
		printf("\n****** MENU ******");
		printf("\n1. Push. ");
		printf("\n2. Pop. ");
		printf("\n3. Display Stack.");
		printf("\n4. Exit.");
		do
		{
			printf("\nEnter your choice : ");
		}while((scanf("%d%c",&choice,&c)==0||c!='\n')&&clean());

		switch(choice)
		{
			case 1 : push(arr, &top );break;
			case 2 : pop(arr, &top);break;
			case 3 : display(arr, &top);break;
			case 4 : exit(0);break;
			default: printf("Error! Enter valid choice.");
		}
	}

	getch();
	return 0;
}
void display(int arr[], int *top)
{
	int counter;
	if(*top == -1)
	{
		printf("\nUnderflow : Nothing to display.");
		return;
	}

	printf("\nSTACK");
	for(counter = *top; counter >= 0; counter--)
	{
		printf("\n%d",arr[counter]);
	}
}
void push(int arr[], int *top)
{
	char yn='y', c;
	while(yn=='y'|| yn=='Y')
	{
		if(*top == MAX-1)
		{
			printf("\nOverflow");
			return;
		}
		(*top)++;
		do
		{
			printf("\nEnter element to push : ");
		}while((scanf("%d%c",&arr[*top],&c)==0||c!='\n')&&clean());

		display(arr, top);
		printf("\nWant to continue : (Y or N) : ");
		fflush(stdin);
		scanf("%c",&yn);
	}
}
void pop(int arr[], int *top)
{
	int counter;
	char yn='y';
	while(yn=='y'||yn=='Y')
	{
		if(*top == -1)
		{
			printf("\nUnderflow");
			return;
		}
		printf("\n'%d' is poped out of stack.\n",arr[*top]);
		(*top)--;
		display(arr, top);
		printf("\nWant to continue : (Y or N) : ");
		fflush(stdin);
		scanf("%c",&yn);
	}
}
int clean()
{
	while( getchar() != '\n')
	{
		return 1;
	}
}