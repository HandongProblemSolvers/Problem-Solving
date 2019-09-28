#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 4

typedef enum {
    false, true
} bool;

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
int blank(int x, int n);
bool even(int x, int n);
int alone(int x, int n);
int maxBit(int x, int n);
int minBit(int x, int n);
int tiling(int col);

int main()
{
    int T, N;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) { 
        scanf("%d", &N);
        printf("%d\n", tiling(N));
    }
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

int blank(int x, int n)
{
    int count = 0;
    
    for (int i = 0; i < n; i++) { 
        if (!(x & 1 << i))
            count++;
    }
    return count;
}

bool even(int x, int n)
{   
    int count = 0;
    bool isConnect = false;

    for (int i = 0; i < n; i++) {
        if (x & 1 << i)
            isConnect = true;
        else if (isConnect)
            isConnect = false;

        if (!isConnect && count) {
            if (count % 2 != 0)
                return false;

            count = 0;
        }

        if (isConnect)
            count++;        
    }

    if (count % 2 != 0)
        return false;
    else     
        return true;
}

int alone(int x, int n)
{
    for (int i = 0; i < n; i++) {
        if (x & 1 << i) {
            if (i == 0) {
                if (!(x & 1 << (i + 1)))
                    return 1 << i;
            }
            else if (i == n - 1) { 
                if (!(x & 1 << (i - 1)))
                    return 1 << i;
            }
            else {
                if (!(x & 1 << (i + 1)) && !(x & 1 << (i - 1)))
                    return 1 << i;
            }
        } 
    }
    return 0;
}

int maxBit(int x, int n)
{
    for (int i = n - 1; i >= 0; i++) { 
        if (x & 1 << i)
            return 1 << i;
    }
    return 0;
}

int minBit(int x, int n)
{
    for (int i = 0; i < n; i++) {
        if (x & 1 << i)
            return 1 << i;
    }
    return 0;
}

int tiling(int col)
{
    int **dp;
    int *b, *e;
    int a;
    int size = 1 << MAX_SIZE;
    int ans = 0;
    int i, j;

    dp = malloc2D(col, size);
    b = (int *) malloc(size * sizeof(int));
    e = (int *) malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        b[i] = blank(i, MAX_SIZE);
        e[i] = even(i, MAX_SIZE) ? 1 : 0;
    }

    dp[0][0] = col > 1 ? 1 : 0;

    for (i = 1; i < size; i++) {
        if (e[i])
            dp[0][i] = 1;
        else 
            dp[0][i] = 0;   
    }

    for (i = 1; i < col; i++) {
        for (j = 0; j < size; j++) {
            if (MAX_SIZE - b[j] == 1 || MAX_SIZE - b[j] == 0 || (MAX_SIZE - b[j] == 2 && !e[j]))
                dp[i][j] = dp[i - 1][size - 1 - j];
            else if (MAX_SIZE - b[j] == 2)    
                dp[i][j] = dp[i - 1][size - 1 - j] + dp[i - 1][size - 1];
            else if (MAX_SIZE - b[j] == 3 && (a = alone(j, MAX_SIZE)))
                dp[i][j] = dp[i - 1][size - 1 - j] + dp[i - 1][size - a];
            else if (MAX_SIZE - b[j] == 3)
                dp[i][j] = dp[i - 1][size - 1 - j] + dp[i - 1][size - minBit(j, MAX_SIZE)] + dp[i - 1][size - maxBit(j, MAX_SIZE)];
            else
                dp[i][j] = dp[i - 1][size - 1 - j] + dp[i - 1][3] + dp[i - 1][6] + dp[i - 1][12] + dp[i - 1][size - 1];    
        }   
    }
    ans = dp[col - 1][size - 1];

    /* 
    printf("even\n");
    for (int i = 0; i < size; i++) 
        printf("%d ", e[i]);
    putchar('\n');    

    printf("blank\n");
    for (int i = 0; i < size; i++) 
        printf("%d ", b[i]);
    putchar('\n');

    printf("alone\n");
    for (int i = 0; i < size; i++)
        printf("%d ", alone(i, MAX_SIZE));
    putchar('\n');    

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", dp[i][j]);
        }
        putchar('\n');
    }
    */

    free2D(dp, col);
    free(b);
    free(e);

    return ans;
}