#include "game.h"

void menu()
{
    printf("**********************\n");
    printf("******  1.play    ****\n");
    printf("*****   0.exit   *****\n");
    printf("**********************\n");
}
void game()
{
    int8_t mine[ROWS][COLS] = {0};
    int8_t show[ROWS][COLS] = {0};
    initboard(mine, ROWS, COLS, '0');
    initboard(show, ROWS, COLS, '*');
    setmine(mine, ROW, COL);
    displayboard(mine, ROW, COL);
    displayboard(show, ROW, COL);
    playing(mine, show, ROW, COL);//输入坐标后进行判断
}
int main()
{
    srand((uint32_t)time(NULL));
    int32_t input = 0;
    do
    {
        menu();
        scanf("%"SCNd32"", &input);
        switch(input)
        {
        case 1:
            game();
            break;
        case 0:
            break;
        default:
            printf("input error,please reenter");
            break;
        }

    } while(input);
    return 0;
}