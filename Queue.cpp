#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#define MAX 5

typedef struct
{
	int q[MAX];
	int front,rear;
}queue;

void enqueue(queue*);
void dequeue(queue*);
void display(queue*);
void create(queue*);

int main()
{
	queue q1;
	unsigned int choice, flag=0;
	char c;
	
	create(&q1);
	
	while(choice != 4)
	{
		if(flag == 1)
		{
			printf("\nEnter for more....");
			getch();
			system("cls");
		}
		printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
		do{
			printf("\nEnter choice :");
			fflush(stdin);
		}while((scanf("%u%c",&choice,&c)==0||c!='\n'||choice>4)&&printf("\nError! Enter valid choice."));
		
		switch(choice)
		{
			case 1: enqueue(&q1);break;
			case 2: dequeue(&q1);break;
			case 3: display(&q1);
		}
		flag = 1;
	}
	return 0;
}

void enqueue(queue* qp)
{
	if(qp->rear == MAX-1)
		printf("\nOverflow : Queue is full.");
	else
	{
		qp->rear++;
		printf("\nEnter elment to insert : ");
		scanf("%d",&qp->q[qp->rear]);
	}
}
void dequeue(queue* qp)
{
	if(qp->rear == -1)
		printf("\nUnderflow : Queue is empty.");
	else
	{
		int item = qp->q[0];
		printf("\nElement deleted : %d",item);
		
		while(qp->front < qp->rear)
		{
			qp->q[qp->front]=qp->q[qp->front+1];
			qp->front++;
		}
		qp->rear--;
		qp->front = 0;
	}	
}
void display(queue* qp)
{
	if(qp->rear == -1)
		printf("\nUnderflow : Queue is empty.");
	else
	{
		printf("\nElements of Queue : ");
		for(int i=0; i<=qp->rear; i++)
		{
			printf("%d\t",qp->q[i]);
		}
	}
}
void create(queue* qp)
{
	qp->front = 0;
	qp->rear = -1;
}
