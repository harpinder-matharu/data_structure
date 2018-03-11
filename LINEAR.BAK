#include<conio.h>
#include<stdio.h>
#define MAX 10
void linear_search(int arr[], int size, int num);
void main()
{
	clrscr();
	int arr[MAX] = {1,14,83,56,83,34,22,90,76,83};
	int size = MAX, num;
	printf("Enter the number to search : ");
	scanf("%d",&num);
	linear_search(arr, size, num);
	getch();
}
void linear_search(int arr[], int size, int num)
{
	int counter,flag=0;
	for(counter = 0; counter < size; counter++)
	{
		if(arr[counter] == num)
		{
			printf("\n%d is present at %d location",num,counter+1);
			flag=1;
		}
	}
	if(flag == 0)
	{
		printf("\n%d is not present in array",num);
	}
}

