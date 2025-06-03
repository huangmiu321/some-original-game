#include "game.h"

void initboard(int8_t arr[ROWS][COLS], int32_t rows, int32_t cols, int8_t set)
{
    for(int32_t i = 0; i < rows; i++)
    {
        for(int32_t j = 0; j < cols; j++)
        {
            arr[i][j] = set;
        }
    }
}

void displayboard(int8_t arr[ROWS][COLS], int32_t row, int32_t col)
{
    printf("--------game---------\n");
    for(int32_t i = 0; i <= row; i++)
    {
        printf(" %" PRId32 "", i);
    }
    printf("\n");
    for(int32_t i = 1; i <= row; i++)
    {
        printf(" %" PRId32 "", i);
        for(int32_t j = 1; j <= col; j++)
        {
            printf(" %c", arr[i][j]);
        }
        printf("\n");
    }
}

void setmine(int8_t arr[ROWS][COLS], int32_t row, int32_t col)
{
    int count = EASY;
    while(count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if(arr[x][y] == '0')
        {
            arr[x][y] = '1';
            count--;
        }
    }
}

void playing(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t row, int32_t col)
{
    int32_t x = 0, y = 0;
    while(1)
    {
        int32_t count = 0;
        for(int32_t i = 1; i <= row; i++)
        {
            for(int32_t j = 1; j <= col; j++)
            {
                if(show[i][j] == '*')

                    count++;
            }
        }
        if(count == 10)
        {

            printf("you are win\n");
            break;
        }

        printf("\nplease input coordinate >");
        scanf("%" SCNd32 " %" SCNd32 "", &x, &y);
        if(x > 0 && x <= row && y > 0 && y <= col)
        {
            if(show[x][y] == '*')
            {
                if(mine[x][y] == '1')
                {
                    printf("game over,you are dead\n");
                    break;
                }
                else
                {

                    expand_out(mine, show, x, y); //自动显示附近一片没有雷的地方
                    displayboard(show, row, col);
                }
            }
            else
            {
                printf("\nthe coordinate is entered");
            }
        }
        else
        {
            printf("enter is lawless");
        }
    }
}

int8_t find_mine(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t x, int32_t y)
{
    int count = 0;
    for(int32_t i = -1; i <= 1; i++)
    {
        for(int32_t j = -1; j <= 1; j++)
        {
            if(x + i > 0 && x + i < ROWS && y + j > 0 && y + j < COLS)
                count = count + mine[x + i][y + j] - '0';
        }
    }
    return count + '0';
}

void expand_out(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t x, int32_t y)
{
    show[x][y] = find_mine(mine, show, x, y); //显示附近八格中有几颗雷
    for(int32_t i = -1; i <= 1; i++)
    {
        for(int32_t j = -1; j <= 1; j++)
        {
            if(x + i > 0 && x + i < ROWS && y + j > 0 && y + j < COLS)
            {
                if(show[x + i][y + j] == '*') //没有被点击过
                {
                    if(mine[x + i][y + j] == '0') //不是雷
                    {
                        int8_t m = find_mine(mine, show, x + i, y + j);
                        if(m == '0')
                        {
                            expand_out(mine, show, x + i, y + j);
                        }
                        else if(m >= '1' && m <= '8')
                        {
                            show[x + i][y + j] = find_mine(mine, show, x + i, y + j);
                        }
                    }
                }
            }
        }
    }
}