#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int row, column, a, b, i, k; //defining variables and arrays in global
double arr[100][100];
double filee[100][100];
double *colT;
double *rowT;

void getd()
{ //function that gets row and column from user
	do
	{
		printf("Enter the row(max=100):");
		scanf("%d", &row);
		if ((row < 1) || row > 100) //check out that if it is between 1 and 100
		{
			fflush(stdin);
			continue;
		}
	} while ((row < 1) || (row > 100));

	do
	{
		printf("Enter the column(max=100):");
		scanf("%d", &column);
		if ((column < 1) || (column > 100))
		{
			fflush(stdin);
			continue;
		}
	} while ((column < 1) || (column > 100));
}

void elements() //getting elements from user and assigning them to array "arr"
{
	int i, k;
	printf("\nEnter the elements\n");

	for (i = 0; i < row; i++)
	{
		for (k = 0; k < column; k++)
			scanf("%lf", &arr[i][k]);
	}
}

void displaym() //displaying filled matrix
{

	int i, k;
	printf("\nFilled matrix\n\n");
	for (i = 0; i < row; i++)
	{
		for (k = 0; k < column; k++)
			printf("%.2lf\t", arr[i][k]);
		printf("\n");
	}
}
void interval() //getting interval from user that will assign 0
{
	int i, k;
	printf("Enter the interval that you want to delete\n");
	printf("initial interval point:");
	scanf("%d", &a);
	printf("end of interval:");
	scanf("%d", &b);
	printf("\nFilled matrix after \n\n");

	for (i = 0; i < row; i++) //checking if the array value is between a and b
	{
		for (k = 0; k < column; k++)
		{
			if ((arr[i][k] > a) && (arr[i][k] < b))
			{
				arr[i][k] = 0;
			}
		}
	}

	for (i = 0; i < row; i++) //printing matrix
	{
		for (k = 0; k < column; k++)
			printf("%.2lf\t", arr[i][k]);
		printf("\n");
	}
}

void fileop()
{ //the function which checks out the text file and makes operations

	FILE *dosya = fopen("kayit.txt", "r");
	if (dosya == NULL)
		printf("Couldn't find file");
	else
	{
		fscanf(dosya, "%d %d", &row, &column);

		for (i = 0; i < row; i++)
		{
			for (k = 0; k < column; k++)
			{
				fscanf(dosya, "%lf", &filee[i][k]);
			}
			k = 0;
		}
	}
	//showing the filled array
	printf("\nFilled array\n");
	for (i = 0; i < row; i++)
	{
		for (k = 0; k < column; k++)
		{
			printf("%.2f\t", filee[i][k]);
		}
		printf("\n");
		k = 0;
	}
	fclose(dosya);

	double *colT = (double *)malloc(sizeof(double) * column); //defining memory location dynamically
	double *rowT = (double *)malloc(sizeof(double) * row);
	double sum = 0;

	for (k = 0; k < column; k++)
	{
		for (i = 0; i < row; i++)
		{
			sum = sum + filee[i][k];
		}
		colT[k] = sum; //assigning sum to colT array
		sum = 0;
	}

	for (i = 0; i < row; i++)
	{
		for (k = 0; k < column; k++)
		{
			sum = sum + filee[i][k];
		}
		rowT[i] = sum; //assigning sum to rowT array
		sum = 0;
	}

	printf("\nColumn Sum Vector\n");
	for (i = 0; i < column; i++)
	{
		printf("%.2f\t", colT[i]);
	}

	printf("\nRow Sum Vector\n");
	for (k = 0; k < row; k++)
	{
		printf("%.2f\n", rowT[k]);
	}

	printf("Enter the interval that you want to delete\n");
	printf("initial interval point:");
	scanf("%d", &a);
	printf("end of interval:");
	scanf("%d", &b);
	printf("\nFilled matrix after \n\n");

	for (i = 0; i < row; i++) //checking if the array value is between a and b
	{
		for (k = 0; k < column; k++)
		{
			if ((filee[i][k] > a) && (filee[i][k] < b))
			{
				filee[i][k] = 0;
			}
		}
	}
	for (i = 0; i < row; i++) //printing matrix
	{
		for (k = 0; k < column; k++)
			printf("%.2f\t", filee[i][k]);
		printf("\n");
	}
}

int main()
{

	int size, i, k, m, a, b;
	double sum = 0;
	getd();
	elements();
	displaym();

	//defining memory location dynamically
	colT = (double *)malloc(sizeof(double) * column);
	rowT = (double *)malloc(sizeof(double) * row);
	printf("\ncolumn sum vector:\n\n");
	for (k = 0; k < column; k++)
	{
		for (i = 0; i < row; i++)
		{
			sum = sum + arr[i][k];
		}
		colT[k] = sum;
		printf("%.2lf\t", colT[k]);
		sum = 0;
	}
	printf("\n\n");
	printf("row sum vector:\n\n");
	for (i = 0; i < row; i++)
	{
		for (k = 0; k < column; k++)
		{
			sum = sum + arr[i][k];
		}
		rowT[i] = sum;
		printf("%.2lf\n", rowT[i]);
		sum = 0;
	}
	printf("\n\n");
	interval();

	fileop();

	getch();
	return 0;
}
