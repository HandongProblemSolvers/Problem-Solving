#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 26

char** malloc2DC(int row, int col);
void free2DC(char **arr, int row);
int** malloc2DI(int row, int col);
void free2DI(int **arr, int row);
int triplet(char **grid, int n);

int main()
{
    char **grid;
    int N;
    int i, j;

    scanf("%d", &N);

    grid = malloc2DC(N, N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) 
            scanf(" %c", &grid[i][j]);
    }   
    printf("%d\n", triplet(grid, N));

    free2DC(grid, N);

    return 0;
}

char** malloc2DC(int row, int col)
{
    char **arr;
    int i;

    arr = (char **) malloc(row * sizeof(char *));

    for (i = 0; i < row; i++) 
        arr[i] = (char *) malloc(col * sizeof(char));
    
    return arr;
}

void free2DC(char **arr, int row)
{
    int i;

    for (i = 0; i < row; i++) 
        free(arr[i]);

    free(arr);    
}

int** malloc2DI(int row, int col)
{
    int **arr;
    int i;

    arr = (int **) malloc(row * sizeof(int *));

    for (i = 0; i < row; i++) 
        arr[i] = (int *) malloc(col * sizeof(int));
    
    return arr;
}

void free2DI(int **arr, int row)
{
    int i;

    for (i = 0; i < row; i++) 
        free(arr[i]);

    free(arr);    
}

int triplet(char **grid, int n)
{
    int **coor;
    int cmp;
    int count = 0;
    int i, j, l;
    int k = 0;

    coor = malloc2DI(MAX_SIZE, 2);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] != '.') {
                coor[k][0] = j;
                coor[k++][1] = i;
            }
        }
    }

    for (i = 1; i < k; i++) {
        cmp = i - 1;
 
        for (j = i; j < k - 1; j++) {
            for (l = j + 1; l < k; l++) {
                if (((coor[j][0] - coor[l][0]) * (coor[cmp][1] - coor[l][1]) - (coor[cmp][0] - coor[l][0]) * (coor[j][1] - coor[l][1])) == 0)
                    count++;
            }
        }
    }
    free2DI(coor, MAX_SIZE);
    
    return count;
}

