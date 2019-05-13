#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define MAX_SIZE 101
#define OPTION_NUM 4

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
void point(int **loc, int *x, int *y, int move);
void denote(int **loc, int *curve);
int countSqr(int **loc);
int dragonSqr(int **curves, int n);

int main() 
{
    int **curves;
    int N;
    int i, j;

    scanf("%d", &N);

    curves = malloc2D(N, OPTION_NUM);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < OPTION_NUM; j++) 
            scanf("%d", &curves[i][j]);
    }
    printf("%d", dragonSqr(curves, N));

    free2D(curves, N);

    return 0;
}

int** malloc2D(int row, int col)
{
    int **arr;
    int i;

    arr = (int **) malloc(row * sizeof(int *));

    for (i = 0; i < row; i++) 
        arr[i] = (int *) malloc(col * sizeof(int));
    
    return arr;
}

void free2D(int **arr, int row)
{
    int i;

    for (i = 0; i < row; i++) 
        free(arr[i]);

    free(arr);    
}

void point(int **loc, int *x, int *y, int move)
{
    if (move == 0)
        loc[*y][++*x] = 1;
    else if (move == 1)
        loc[--*y][*x] = 1;
    else if (move == 2)
        loc[*y][--*x] = 1;
    else
        loc[++*y][*x] = 1;            
}

void denote(int **loc, int *curve)
{
    int **move;
    int prev_col;
    int row = curve[3] + 1, col = pow(2, curve[3]);
    int x = curve[0], y = curve[1];
    int i, j;

    move = malloc2D(row, col);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) 
            move[i][j] = -1;
    }
    loc[y][x] = 1;

    for (i = 0; i < row; i++) {
        prev_col = col;
        col = pow(2, i);

        for (j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                move[i][j] = curve[2];

                point(loc, &x, &y, move[i][j]);
            }
            else if (move[i - 1][j] != -1)
                move[i][j] = move[i - 1][j];
            else { 
                move[i][j] = (move[i - 1][--prev_col] + 1) % OPTION_NUM;

                point(loc, &x, &y, move[i][j]);
            }
        }
    }
    free2D(move, row);
}

int countSqr(int **loc)
{   
    int part;
    int count = 0;
    int i, j;

    for (i = 0; i < MAX_SIZE - 1; i++) {
        part = 0;

        for (j = 0; j < MAX_SIZE; j++) {
            if (loc[i][j] && loc[i + 1][j])
                part++;
            else 
                part = 0;    
            
            if (part >= 2)
                count++;
        }
    }
    return count;
}

int dragonSqr(int **curves, int n)
{
    int **loc;
    int count;
    int i, j;

    loc = malloc2D(MAX_SIZE, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) 
            loc[i][j] = 0;
    }

    for (i = 0; i < n; i++) 
        denote(loc, curves[i]);

    count = countSqr(loc);

    free2D(loc, MAX_SIZE);

    return count;
}

