#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 3
#define MAX_NUM 1

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
int min(int a, int b);
void minChange(int **change, int **v, int n, int num);

int main()
{   
    int **v, **change;
    int n, m;
    int k;
    int s, e;

    scanf("%d %d", &n, &m);

    change = malloc2D(n, n);
    v = malloc2D(m, MAX_SIZE);

    for (int i = 0; i < m; i++) 
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
    
    minChange(change, v, m, n);

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", change[s - 1][e - 1]);
    }    
    free2D(change, n);
    free2D(v, m);

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

int min(int a, int b)
{
    return a < b ? a : b;
}

void minChange(int **change, int **v, int n, int num)
{
    int INF = num * MAX_NUM;
    int i, j, k;

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) 
            change[i][j] = i == j ? 0 : INF;
    }

    for (i = 0; i < n; i++) {
        change[v[i][0] - 1][v[i][1] - 1] = 0;
        change[v[i][1] - 1][v[i][0] - 1] = v[i][2] ? 0 : 1;
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            for (k = 0; k < num; k++) 
                change[j][k] = min(change[j][i] + change[i][k], change[j][k]);        
        }
    }

    /* 
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) 
            printf("%d ", change[i][j]);
        putchar('\n');    
    }
    */
}
