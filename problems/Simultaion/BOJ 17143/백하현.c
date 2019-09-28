#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 5
#define ROW 0
#define COL 1
#define SPD 2
#define DIR 3
#define SIZE 4
#define TOP 1
#define BOT 2
#define RIGHT 3
#define LEFT 4

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
int delete(int ***num, int h, int r, int c, int **fish, int loc);
void move(int ***num, int h, int r, int c, int **fish);
int sumSize(int **fish, int n, int r, int c);

int main()
{
    int **fish;
    int R, C, M;

    scanf("%d %d %d", &R, &C, &M);

    fish = malloc2D(M, MAX_SIZE);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < MAX_SIZE; j++) 
            scanf("%d", &fish[i][j]);
    }
    printf("%d\n", sumSize(fish, M, R, C));

    free2D(fish, M);

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

int delete(int ***num, int h, int r, int c, int **fish, int loc)
{
    int size = 0;

    for (int i = 0; i < r; i++) {
        if (num[h][i][loc]) {
            size = fish[num[h][i][loc] - 1][SIZE];
            num[h][i][loc] = 0;

            break;
        }
    }
    return size;
}

void move(int ***num, int h, int r, int c, int **fish)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int speed;
            int ri, ci;

            if (num[h - 1][i][j]) {
                speed = fish[num[h - 1][i][j] - 1][SPD]; 
                
                if (fish[num[h - 1][i][j] - 1][DIR] == TOP) {
                    ci = j;

                    if (speed <= i) 
                        ri = i - speed;
                    else {
                        if ((speed - i) / (r - 1) % 2 == 0) {
                            ri = (speed - i) % (r - 1);
                            fish[num[h - 1][i][j] - 1][DIR] = BOT;
                        } 
                        else
                            ri = r - 1 - (speed - i) % (r - 1);     
                    }
                }
                else if (fish[num[h - 1][i][j] - 1][DIR] == BOT) {
                    ci = j;

                    if (speed <= r - 1 - i)
                        ri = i + speed;
                    else {
                        if ((speed - (r - 1 - i)) / (r - 1)  % 2 == 0) {
                            ri = r - 1 - (speed - (r - 1 - i)) % (r - 1);
                            fish[num[h - 1][i][j] - 1][DIR] = TOP;
                        }
                        else 
                            ri = (speed - (r - 1 - i)) % (r - 1);
                    }    
                }
                else if (fish[num[h - 1][i][j] - 1][DIR] == RIGHT) {
                    ri = i;

                    if (speed <= c - 1 - j)
                        ci = j + speed;
                    else {
                        if ((speed - (c - 1 - j)) / (c - 1) % 2 == 0) { 
                            ci = c - 1 - (speed - (c - 1 - j)) % (c - 1);
                            fish[num[h - 1][i][j] - 1][DIR] = LEFT;
                        }
                        else 
                            ci = (speed - (c - 1 - j)) % (c - 1);   
                    }    
                }
                else if (fish[num[h - 1][i][j] - 1][DIR] == LEFT) {
                    ri = i;

                    if (speed <= j)
                        ci = j - speed;
                    else {
                        if ((speed - j) / (c - 1) % 2 == 0) {
                            ci = (speed - j) % (c - 1);
                            fish[num[h - 1][i][j] - 1][DIR] = RIGHT;
                        }
                        else 
                            ci = c - 1 - (speed - j) % (c - 1);
                    }
                }

                if (!num[h][ri][ci] || fish[num[h - 1][i][j] - 1][SIZE] > fish[num[h][ri][ci] - 1][SIZE])
                    num[h][ri][ci] = num[h - 1][i][j]; 
            }
        }
    }
}

int sumSize(int **fish, int n, int r, int c)
{
    int ***num;
    int sum = 0;
    int i, j, k;

    num = (int ***) malloc((c + 1) * sizeof(int **));

    for (i = 0; i <= c; i++) 
        num[i] = malloc2D(r, c);

    for (i = 0; i <= c; i++) {
        for (j = 0; j < r; j++) {
            for (k = 0; k < c; k++) 
                num[i][j][k] = 0;
        }
    }

    for (i = 0; i < n; i++) 
        num[0][fish[i][ROW] - 1][fish[i][COL] - 1] = i + 1;
    
    for (i = 0; i < c; i++) {
        /* 
        printf("i = %d, sum = %d\n", i, sum);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++)
                printf("%d ", num[i][j][k]);
            putchar('\n');   
        }
        putchar('\n');
        */
       
        sum += delete(num, i, r, c, fish, i);
    
        move(num, i + 1, r, c, fish);
    }

    for (i = 0; i <= c; i++)
        free2D(num[i], r);
    
    return sum;
}