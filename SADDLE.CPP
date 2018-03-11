#include<stdio.h>
#include<conio.h>

int findSaddlePoint(int mat[][3], int n);

int main()
{
	clrscr();
	int mat[3][3] =    {{9, 8, 7},
			{6, 5, 4},
			{3, 2, 1}};
    if (findSaddlePoint(mat, 3) == 0)
       printf( "No Saddle Point ");
    getch();
    return 0;
}
int findSaddlePoint(int mat[][3], int n)
{
    // Process all rows one by one
    for (int i = 0; i < n; i++)
    {
	// Find the minimum element of row i.
	// Also find column index of the minimum element
	int min_row = mat[i][0], col_ind = 0;
	for (int j = 1; j < n; j++)
	{
	    if (min_row > mat[i][j])
	    {
		min_row = mat[i][j];
		col_ind = j;
	    }
	}

	// Check if the minimum element of row is also
	// the maximum element of column or not
	int k;
	for (k = 0; k < n; k++)

	    // col_ind is fixed
	    if (min_row < mat[k][col_ind])
		break;

	// If saddle point is present in this row then
	// print it
	if (k == n)
	{
	   printf("Value of Saddle Point %d",min_row);
	   return 1;
	}
    }

    // If Saddle Point not found
    return 0;
}