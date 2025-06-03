#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

void initboard(char arr[ROW][COL], int row, int col);
void menu();
void displayboard(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col, int* x, int* y);
void computermove(char arr[ROW][COL], int row, int col, int* x, int* y);
char iswin(char arr[ROW][COL], int row, int col, int* x, int* y);