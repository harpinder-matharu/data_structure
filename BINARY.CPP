#include<conio.h>
#include<stdio.h>
#define MAX 10
int binary_search(int arr[], int beg, int end, int num);
void main()
{
	clrscr();
	int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};
	int size = MAX, num, loc = -1;
	printf("Enter the number to search : ");
	scanf("%d",&num);
	loc = binary_search(arr,1, size, num);
	if(loc != -1)
	{
		printf("\n%d is present at %d location",num,loc + 1);
	}
	else
	{
		printf("\n%d is not present in array",num);
	}
	getch();
}
int binary_search(int arr[],int beg, int end, int num)
{
	int mid, loc = -1;
	while(beg <= end)
	{
		mid = (beg + end) / 2;
		if(arr[mid] == num)
		{
			loc = mid;
			break;
		}
		else if(arr[mid] < num)
		{
			beg = mid + 1;
		}
		else //if(arr[mid] > num)
		{
			end = mid - 1;
		}
	}
	return loc;
}

