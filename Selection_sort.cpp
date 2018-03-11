#include "conio.h"
#include "stdio.h"
#define MAX 10

void selection_sort(int arr[], int n);
void display(int arr[], int n);

int main()
{
	int size = MAX, arr[size], i;
	char c;
	
	printf("\nEnter %d elements in array",size);
	
	for(i = 0; i < size; i++)
	{
		do{
			printf("\nElement arr[%d] : ",i);
			fflush(stdin);
		}while((scanf("%d%c", &arr[i], &c)==0||c!='\n')&&printf("\nEnter only integer value"));
	}
	
	printf("\nBefore sorting");
	display(arr,size);
	
	selection_sort(arr, size);
	
	printf("\nAfter sorting");
	display(arr,size);
	
	getch();
	return 0;
}

void display(int arr[], int n)
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}

void selection_sort(int arr[],int n)
{
	int temp, i, j, loc;
	
	for(i=0; i<n-1; i++)
	{
		loc = i;
		
		for(j = i+1; j < n; j++)
		{
			if(arr[loc]>arr[j])
			{
				loc=j;
			}
		}
		temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	}
}


















