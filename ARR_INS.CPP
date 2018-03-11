#include <stdio.h>
#include <conio.h>
#define MAX 20

void insert(int arr[], int *size_ptr);
void deletion(int arr[], int *size_ptr);
void display(int arr[], int *size_ptr);
void main()
{
	clrscr();
	int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};
	int size = 10;
	int *size_ptr = &size;

	insert(arr, size_ptr);
	deletion(arr, size_ptr);
	getch();
}
void insert(int arr[], int *size_ptr)
{
	int size = *size_ptr, position, new_element, counter;

	printf("\nBefore insertion  : ");
	display(arr, size_ptr);
	printf("\nEnter new element : ");
	scanf("%d", &new_element);
	printf("Enter the position for new element : ");
	scanf("%d", &position);
	for(counter = size; counter >= position; counter--)
	{
		arr[counter] = arr[counter - 1];
	}
	arr[position - 1] = new_element;
	(*size_ptr)++;
	printf("After insertion   : ");
	display(arr, size_ptr);
}
void deletion(int arr[], int *size_ptr)
{
	int size = *size_ptr, counter, position;

	printf("\nBefore deletion   : ");
	display(arr, size_ptr);
	printf("\nEnter the position of element you want to delete : ");
	scanf("%d",&position);
	for(counter = position; counter <= size; counter++)
	{
		arr[counter - 1] = arr[counter];
	}
	(*size_ptr)--;
	printf("After deletion    : ");
	display(arr, size_ptr);
}
void display(int arr[], int *size_ptr)
{
	int counter, size = *size_ptr;

	for(counter = 0; counter < size; counter ++)
	{
		printf("%d ", arr[counter]);
	}
}


