#include "game.h"


void initboard(char arr[ROW][COL], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void menu()
{
	printf("******************************\n");
	printf("******************************\n");
	printf("******* 1.play  0.exit********\n");
	printf("******************************\n");
	printf("******************************\n");
}
void displayboard(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int i = 0; i < col; i++)
			{
				printf("---");
				if (i < col - 1)
					printf("|");
				
			}
			printf("\n");
		}
		
	}
}
void playermove(char arr[ROW][COL], int row, int col, int* x, int* y)
{
	
	
	while (1)
	{
		printf("please player move\n");
		printf("please input coordinate :>");
		scanf_s("%d%d", x, y);
		if (*x >= 1 && *x <= row && *y >= 1 && *y <= col && arr[*x -1][*y - 1] == ' ')
		{
			arr[--*x][--*y] = '*';
			break;
		}
		else
		{
			printf("entered coordinate is illegal,please re-enter\n");
		}
	}
	
}
void computermove(char arr[ROW][COL], int row, int col, int* x, int* y)
{
	while (1)
	{
		*x = rand() % row;
		*y = rand() % col;
		printf("computer move :\n");
		if (arr[*x][*y] == ' ')
		{
			arr[*x][*y] = '#';
			break;
		}
	}
	
}
char isfull(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}


		}
	}
	return 1;
}

char iswin(char arr[ROW][COL], int row, int col, int* x, int* y)
{
	if (arr[*x][0] == arr[*x][1] && arr[*x][1] == arr[*x][2] && arr[*x][0] != ' ')
	{
		return arr[*x][0];
	}
	if (arr[0][*y] == arr[1][*y] && arr[1][*y] == arr[2][*y] && arr[0][*y] != ' ')
	{
		return arr[0][*y];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (isfull(arr, row, col))
	{
		return 'q';
	}
	return 'c';
}