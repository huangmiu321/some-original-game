#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY 10

void initboard(int8_t arr[ROWS][COLS], int32_t rows, int32_t cols, int8_t set);
void displayboard(int8_t arr[ROWS][COLS], int32_t row, int32_t col);
void setmine(int8_t arr[ROWS][COLS], int32_t row, int32_t col);
void playing(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t row, int32_t col);
int8_t find_mine(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t x, int32_t y);
 void expand_out(int8_t mine[ROWS][COLS], int8_t show[ROWS][COLS], int32_t x, int32_t y);
