
#include <stdio.h>
#include <malloc.h>

#define MAX_NUM 2

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
int max(int a, int b);
int maxScore(int *score, int n);

int main()
{
    int *score;
    int N;

    scanf("%d", &N);

    score = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) 
        scanf("%d", &score[i]);

    printf("%d\n", maxScore(score, N));

    free(score);

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

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxScore(int *score, int n)
{
    int ***dp;
    int size = MAX_NUM * (n / (MAX_NUM + 1)) + n % (MAX_NUM + 1);
    int ans = 0;
    int i, j, k;

    dp = (int ***) malloc(size * sizeof(int **));

    for (i = 0; i < size; i++) {
        dp[i] = malloc2D(MAX_NUM, n + 1);

        for (j = 0; j < MAX_NUM; j++) {
            for (k = 0; k <= n; k++) 
                dp[i][j][k] = 0;
        }
    }
    dp[0][0][1] = score[0];
    dp[0][0][2] = score[1];

    for (i = 1; i < size; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            for (k = 0; k <= n; k++) {
                if (dp[i - 1][j][k]) {
                    if (j == 0 && k + 1 <= n)  
                        dp[i][j + 1][k + 1] = dp[i - 1][j][k] + score[k];

                    if (k + 2 <= n)
                        dp[i][0][k + 2] = max(dp[i - 1][j][k] + score[k + 1], dp[i][0][k + 2]);
                }
            }
        }

        for (j = 0; j < MAX_NUM; j++)
            ans = max(ans, dp[i][j][n]);
    }
    
    /* 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_NUM; j++) {
            for (int k = 0; k <= n; k++) {
                printf("%d ", dp[i][j][k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    */

    for (i = 0; i < size; i++) 
        free2D(dp[i], MAX_NUM);

    free(dp);

    return ans;    
}