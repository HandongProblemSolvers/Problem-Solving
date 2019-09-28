#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 2
#define MODULUS 1000000

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
int sumCol(int **arr, int c, int s, int e);
int line(int n);

int main()
{
    int N;

    scanf("%d", &N);
    printf("%d\n", line(N));

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

int sumCol(int **arr, int c, int s, int e)
{
    int sum = 0;

    for (int i = s; i <= e; i++) 
        sum += arr[i][c];

    return sum % MODULUS;
}

int line(int n)
{
    if (n == 1)
        return 1;

    int ***dp;
    int sum = 0;
    int i, j, k;

    dp = (int ***) malloc((n + 1) * sizeof(int **));

    for (i = 0; i <= n; i++)
        dp[i] = malloc2D(n, MAX_SIZE);

    for (i = 0; i <= n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < MAX_SIZE; k++) 
                dp[i][j][k] = 0;  
        }  
    }    
    dp[1][0][0] = dp[1][0][1] = 1;

    for (i = 2; i <= n; i++) {
        for (j = 0; j < i; j++) {
            for (k = 0; k < MAX_SIZE; k++) {
                if (j == 0 && k == 0)
                    dp[i][j][k] = 0;
                else if (j == i - 1 && k == 1)
                    dp[i][j][k] = 0;
                else if (k == 0)        
                    dp[i][j][k] = sumCol(dp[i - 1], -k + 1, 0, j - 1);
                else 
                    dp[i][j][k] = sumCol(dp[i - 1], -k + 1, j, i - 2);
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) 
            sum += dp[n][i][j];
    }

    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < MAX_SIZE; k++) 
                printf("%d ", dp[i][j][k]);
            putchar('\n');    
        }
        putchar('\n');
    }
    printf("%d\n", sum);
    */

    for (i = 0; i <= n; i++)
        free2D(dp[i], n);

    free(dp);

    return sum % MODULUS;    
}
