#include <stdio.h>
#include <malloc.h>

#define MAX_NUM 4
#define MAX_SIZE 8
#define RIGHT 3
#define LEFT 7

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
void distrb(int *arr, int n, int val);
void shift(int *arr, int n, int dir);
void rotate(int **gear, int num, int dir);
int calc(int **gear);

int main()
{
    int **gear;
    int val;
    int K;
    int num, dir;

    gear = malloc2D(MAX_NUM, MAX_SIZE);

    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &val);
        distrb(gear[i], MAX_SIZE, val);
    }
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &num, &dir);
        rotate(gear, num, dir);
    }
    printf("%d\n", calc(gear));

    free2D(gear, MAX_NUM);

    return 0;
}

int** malloc2D(int row, int col)
{
    int **arr;

    arr = (int **) malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++) 
        arr[i] = (int *) malloc(col * sizeof(int));

    return arr;
}

void free2D(int **arr, int row)
{
    for (int i = 0; i < row; i++) 
        free(arr[i]);

    free(arr);    
}

void distrb(int *arr, int n, int val)
{
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = val % 10;
        val /= 10;
    }
}

void shift(int *arr, int n, int dir)
{
    int curr = arr[0];
    int next;

    for (int i = 0; i < n; i++) {
        if (dir == 1) {
            curr = next;
            next = arr[i];
            arr[i] = i == 0 ? arr[n - 1] : curr;
        }
        else 
            arr[i] = i == n - 1 ? curr : arr[i + 1]; 
    }
}

void rotate(int **gear, int num, int dir)
{
    int curr;
    int next = 0;
    int i;

    if (num - 2 >= 0)
        next = gear[num - 1][LEFT - 1] == gear[num - 2][RIGHT - 1] ? 0 : -dir; 

    for (i = num - 2; i > 0 && next; i--) {
        curr = next;
        next = gear[i][LEFT - 1] == gear[i - 1][RIGHT - 1] ? 0 : -curr;
    
        shift(gear[i], MAX_SIZE, curr);
    }
    
    if (next != 0) 
        shift(gear[i], MAX_SIZE, next);

    next = 0;

    if (num < MAX_NUM)
        next = gear[num - 1][RIGHT - 1] == gear[num][LEFT - 1] ? 0 : -dir;

    for (i = num; i <= MAX_NUM - 2 && next; i++) {
        curr = next;
        next = gear[i][RIGHT - 1] == gear[i + 1][LEFT - 1] ? 0 : -curr;

        shift(gear[i], MAX_SIZE, curr);
    }

    if (next != 0) 
        shift(gear[i], MAX_SIZE, next);

    shift(gear[num - 1], MAX_SIZE, dir);

    /* 
    for (int i = 0; i < MAX_NUM; i++) {
        for (int j = 0; j < MAX_SIZE; j++) 
            printf("%d", gear[i][j]);
        putchar('\n');
    }
    */
}

int calc(int **gear)
{
    int sum = 0;

    for (int i = 0; i < MAX_NUM; i++) 
        sum += gear[i][0] == 1 ? 1 << i : 0;

    return sum;
}