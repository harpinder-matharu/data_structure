// Saddle points.cpp :A saddle point of a matrix is an element which is both the largest element in its column and the smallest element in its row.


#include "stdio.h"
#include "conio.h"

void enterdata(int matrix[][10], int *row, int *col);
void display(int matrix[][10], int *row, int *col);
void saddle(int matrix[][10], int *row, int *col);

int main(int argc, char* argv[])
{
	int row, col, matrix[10][10];

	//clrscr();
	enterdata(matrix, &row, &col);
	display(matrix, &row, &col);
	saddle(matrix, &row, &col);

	getch();
	return 0;
}

void enterdata(int matrix[][10], int *row, int *col)
{
	printf("Enter No of rows : ");
	scanf("%d", row);
	printf("Enter no of columns : ");
	scanf("%d", col);

	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf("Enter element a[%d][%d] : ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}
}

void display(int matrix[][10], int *row, int *col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void saddle(int matrix[][10], int * row, int * col)
{
	int min_row, j, flag = 0;
	for (int i = 0; i < *row; i++)
	{
		int min_row = matrix[i][0], col_id = 0;
		for (j = 1; j < *col; j++)
		{
			if (min_row > matrix[i][j])
			{
				min_row = matrix[i][j];
				col_id = j;
			}
		}
		int k;
		for (k = 0; k < *row; k++)
		{
			if (min_row < matrix[k][col_id])
			{
				break;
			}
		}
		if(k == *row)
		{
			flag = 1;
			printf("Saddle point is : %d", min_row);
		}
	}
	if(flag == 0)
	{
		printf("Saddle point does't exist");
	}
}
