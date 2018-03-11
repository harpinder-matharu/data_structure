#include <conio.h>
#include <stdio.h>
#define MAX 10

void bubble_sort(int arr[], int size);
void display(int arr[], int size);
void main()
{
	int arr[MAX] = {10,9,8,7,6,5,4,3,2,1};
	clrscr();

	printf("\nBefore sorting : ");
	display(arr, MAX);
	bubble_sort(arr, MAX);
	printf("\nAfter sorting  : ");
	display(arr, MAX);
	getch();
}
void bubble_sort(int arr[], int size)
{
	int temp, pass_counter, swap_counter;

	for(pass_counter = 1; pass_counter <= size - 1; pass_counter ++)
	{
		for(swap_counter = 0; swap_counter <= size - pass_counter - 1; swap_counter ++)
		{
			if( arr[swap_counter] > arr[swap_counter + 1])
			{
				temp = arr[swap_counter];
				arr[swap_counter] = arr[swap_counter + 1];
				arr[swap_counter + 1] = temp;
			}
		}
	}

}
void display(int arr[], int size)
{
	int counter;

	for(counter = 0; counter < size; counter ++)
	{
		printf("%d ",arr[counter]);
	}
}
