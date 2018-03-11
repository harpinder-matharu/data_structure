#include "conio.h"
#include "stdio.h"
#define MAX 10

int clean()
{
	while(getchar()!='\n')
	{
		return 1;
	}
	return 1;
}

void merge_sort(int arr[], int beg, int end);
void merge(int arr[], int beg, int mid, int end);
void display(int arr[], int n);

int main()
{
	int size = MAX, beg = 0, end, arr[size], i;
	char c;
	end = size-1;
	
	printf("\nEnter %d elements in array",size);
	
	for(i = 0; i < size; i++)
	{
		do{
			printf("\nElement arr[%d] : ",i);
			//fflush(stdin);
		}while((scanf("%d%c", &arr[i], &c)==0||c!='\n')&&printf("\nEnter only integer value")&&clean());
	}
	
	printf("\nBefore sorting");
	display(arr,size);
	
	merge_sort(arr, beg, end);
	
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

void merge_sort(int arr[], int beg, int end)
{
	int mid;
	mid = (beg+end)/2;
	if(beg<end)
	{
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}
void merge(int arr[], int beg, int mid, int end)
{
	int lindex, rindex, tindex, temp[MAX];
	lindex = beg;
	rindex = mid+1;
	tindex = beg;
	
	while((lindex<=mid) && (rindex<=end))
	{
		if(arr[lindex] < arr[rindex])
		{
			temp[tindex] = arr[lindex];
			lindex++;
		}
		else
		{
			temp[tindex] = arr[rindex];
			rindex++;
		}
		tindex++;
	}
	while(lindex<=mid)
	{
		temp[tindex] = arr[lindex];
		lindex++;
		tindex++;
	}
	while(rindex<=end)
	{
		temp[tindex] = arr[lindex];
		rindex++;
		tindex++;
	}
	for(int i=beg; i<=end; i++)
	{
		arr[i] = temp[i];
	}
}

















