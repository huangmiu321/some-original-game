#include "game.h"

char arr[ROW][COL];
void game()
{
	initboard(arr, ROW, COL);
	displayboard(arr, ROW, COL);
	char ret = 0;
	int x = 0, y = 0;
	while (1)
	{
		playermove(arr, ROW, COL, &x, &y);
		displayboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL, &x, &y);
		if (ret == '*')
		{
			printf("game over,player win\n");
			break;
		}
		else if (ret == '#')
		{
			printf("game over,computer win\n");
			break;
		}
		else if (ret == 'q')
		{
			printf("game over,draw\n");
			break;
		}
		computermove(arr, ROW, COL, &x, &y);
		displayboard(arr, ROW, COL);
		ret = iswin(arr, ROW, COL, &x, &y);
		if (ret == '*')
		{
			printf("game over,player win\n");
			break;
		}
		else if (ret == '#')
		{
			printf("game over,computer win\n");
			break;
		}
		else if (ret == 'q')
		{
			printf("game over,draw\n");
			break;
		}
	}
	
}
int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("please input :");	
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("please input again");
			break;
		}
		
	} while (a);
	
	return 0;
}