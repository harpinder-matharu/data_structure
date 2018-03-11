#include<conio.h>
#include<stdio.h>
#define MAX 10
int binary_search(int arr[], int beg, int end, int num);
void main()
{
	clrscr();
	int arr[MAX] = {1,2,5,9,9,9,5,5,9,10};
	int size = MAX, num;
	printf("Enter the number to search : ");
	scanf("%d",&num);
	int oh=binary_search(arr,1, size, num);
	printf("%d",oh+1);
	getch();
}
int binary_search(int arr[],int beg, int end, int num)
{
	int counter, flag = 0, mid;
	if(beg > end)
	return -1;

		mid = (beg + end) / 2;
		if(arr[mid] == num)
		{
			return mid;
			//printf("\n%d is present at %d location",num,mid+1);
			//flag = 1;
		}
		else if(arr[mid] < num)
		{
			return binary_search(arr, mid + 1, end, num);
		       //	beg = mid + 1;
		}
		else //if(arr[mid] > num)
		{
			return binary_search(arr, beg, mid - 1, num);
			//end = mid - 1;
		}

  /*	if(flag == 0)
	{
		printf("\n%d is not present in array",num);
	}*/
}

