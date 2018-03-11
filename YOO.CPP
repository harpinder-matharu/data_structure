// Saddle points.cpp :A saddle point of a matrix is an element which is both the largest element in its column and the smallest element in its row.


#include "stdio.h"
#include "conio.h"

void enterdata(int matrix[][10], int *row, int *col);

int main(int argc, char* argv[])
{
	int *rowPtr, *colPtr, row, col, matrix[10][10];
	rowPtr = &row; colPtr = &col;

	enterdata(matrix, rowPtr, colPtr);
	printf("\n");
	getch();
    return 0;
}


void enterdata(int matrix[][10], int *row, int *col)
{
	printf("Enter No of rows");
	scanf("%d", row);
	printf("Enter no of columns");
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
