#include "conio.h"
#include "stdio.h"
#include "math.h"

void insert(int tree[], int size)
{
	printf("\nEnter data in breadth first order(level wise).\nEnter -1 if there is no node.");
	
	printf("\nEnter nodes :\n")
	for(int i; i<size; i++)
	scanf("%d",&tree[i]);
}

void preoder(int tree[], int size,height)
{
	int stack[heigth], top=0, ptr;
	stack[top]=0;
	while(top != -1)
	{
		ptr = stack[top];
		top=top-1;
		while(tree[ptr] != -1)
		{
			printf("%d",tree[ptr]);
			
		}
	}
}

int main()
{
	int height, size;
	printf("\nEnter the height of tree : ");
	scanf("%d",&height);
	size = pow(2,height+1) - 1;
	int tree[size];
	
	insert(tree,size);
	
	return 0;
}
