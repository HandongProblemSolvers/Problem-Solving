#include <stdio.h>
#include <malloc.h>

void malloc2D(int ***arr, int row, int col);
int min(int a, int b);
void free2D(int *arr[], int row);
int NumMinterm(int n);

int main()
{
    int N;

    scanf("%d", &N);
    
    printf("%d\n", NumMinterm(N));

    return 0;
}

void malloc2D(int ***arr, int row, int col)
{
    int i;

    *arr = (int **) malloc(row * sizeof(int *));

    for (i = 0; i < row; i++) 
        (*arr)[i] = (int *) malloc(col * sizeof(int));
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void free2D(int *arr[], int row)
{
    int i;

    for (i = 0; i < row; i++) 
        free(arr[i]);
}

int NumMinterm(int n)
{   
    int **min_count;
    int *s_num;
    int base = 1;
    int max_base;
    int c_count;
    int ans;
    int i, j;

    while (base * base <= n) {
        max_base = base;
        base++;
    }

    s_num = (int *) malloc(max_base * sizeof(int));

    for (i = 0; i < max_base; i++) 
        s_num[i] = (i + 1) * (i + 1);   

    malloc2D(&min_count, max_base, n + 1);

    for (i = 0; i < max_base; i++) {
        min_count[i][0] = 0;

        for (j = 1; j <= n; j++) {
            c_count = j / s_num[i];

            if (i == 0)
                min_count[i][j] = c_count;
            else
                min_count[i][j] = min(c_count + min_count[i - 1][j - c_count * s_num[i]], min_count[i - 1][j]);            
        }
    }
    ans = min_count[max_base - 1][n];

    free(s_num);
    free2D(min_count, max_base);
    free(min_count);

    return ans;    
}