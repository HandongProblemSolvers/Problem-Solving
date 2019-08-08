#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define MAX_NUM 1000000

typedef enum {
    false, true
} bool;

bool ascen(int *arr, int a, int b);
void swap(int *arr, int a, int b);
void sink(int *arr, int n, int k, bool (*fp) (int *, int, int));
void heapify(int *arr, int n, bool (*fp) (int *, int, int));
void delete(int *arr, int n, int k, bool (*fp) (int *, int, int));
void heapsort(int *arr, int n, bool (*fp) (int *, int, int));
int find(int *arr, int n, int x);
int minDiff(int *bc, int n, int *gc, int m);

int main()
{
    int *bc, *gc;
    int n, m;

    scanf("%d %d", &n, &m);

    bc = (int *) malloc((n + 1) * sizeof(int));
    gc = (int *) malloc((m + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) 
        scanf("%d", &bc[i]);

    for (int i = 1; i <= m; i++) 
        scanf("%d", &gc[i]);     

    printf("%d\n", minDiff(bc, n, gc, m));

    free(bc);
    free(gc);

    return 0;
}

bool ascen(int *arr, int a, int b)
{
    return arr[a] > arr[b];
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];

    arr[a] = arr[b];
    arr[b] = temp;    
}

void sink(int *arr, int n, int k, bool (*fp) (int *, int, int))
{
    while (2 * k <= n) {
        int cmp = 2 * k + 1 > n || fp(arr, 2 * k, 2 * k + 1) ? 2 * k : 2 * k + 1;

        if (!fp(arr, k, cmp))
            swap(arr, k, cmp);
        else 
            break;

        k = cmp;        
    }
}

void heapify(int *arr, int n, bool (*fp) (int *, int, int))
{
    for (int i = n / 2; i >= 1; i--)
        sink(arr, n, i, fp);
}

void delete(int *arr, int n, int k, bool (*fp) (int *, int, int))
{
    swap(arr, k, n);
    sink(arr, n - 1, k, fp);
}

void heapsort(int *arr, int n, bool (*fp) (int *, int, int))
{
    heapify(arr, n, fp);

    for (int i = n; i >= 1; i--) 
        delete(arr, i, 1, fp);
}

int find(int *arr, int n, int x)
{   
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            if (i == 0)
                return i;
            else 
                return i - 1;    
        }
    }    
    return n - 1;
}

int minDiff(int *bc, int n, int* gc, int m)
{
    int *dp;
    int *std, *cmp;
    int index;
    int left, right;
    int s_size, c_size;
    int ans;

    heapsort(bc, n, ascen);
    heapsort(gc, m, ascen);

    if (n < m) {
        std = bc;
        cmp = gc;
        s_size = n;
        c_size = m;

        dp = (int *) malloc((s_size + 1) * sizeof(int));
    }
    else {
        std = gc;
        cmp = bc;
        s_size = m;
        c_size = n;

        dp = (int *) malloc((s_size + 1) * sizeof(int));    
    }
    index = find(&cmp[1], n, std[1]) + 1;
    dp[0] = 0;
    
    if (index + 1 > c_size || abs(std[1] - cmp[index]) < abs(std[1] - cmp[index + 1])) {
        left = index - 1;
        right = index + 1; 
        dp[1] = abs(std[1] - cmp[index]);
    }
    else {
        left = index;
        right = index + 2;
        dp[1] = abs(std[1] - cmp[index + 1]);
    } 

    for (int i = 2; i <= s_size; i++) {
        int ld = left <= 0 ? MAX_NUM : abs(std[i] - cmp[left]);
        int rd = right > c_size ? MAX_NUM : abs(std[i] - cmp[right]);
        
        if (ld < rd) {
            dp[i] = dp[i - 1] + ld;
            left -= 1;
        }    
        else {
            dp[i] = dp[i - 1] + rd; 
            right += 1;
        }
    }
    ans = dp[s_size];

    /* 
    for (int i = 1; i <= n; i++) 
        printf("%d ", bc[i]);
    putchar('\n');

    for (int i = 1; i <= m; i++) 
        printf("%d ", gc[i]);
    putchar('\n');        

    for (int i = 0; i <= s_size; i++)
        printf("%d ", dp[i]);
    putchar('\n');    
    */

    free(dp);

    return ans;
}