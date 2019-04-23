#include <stdio.h>
#include <malloc.h>

double combin(int n, int r);
double colorPer(int *count, int n, int k);

int main()
{
    int *count;
    int M, K;
    double ans;
    int i;

    scanf("%d", &M);

    count = (int *) malloc(M * sizeof(int));

    for (i = 0; i < M; i++) 
        scanf("%d", &count[i]);

    scanf("%d", &K);

    ans = colorPer(count, M, K);

    if (ans == 1)
        printf("%.1lf\n", ans);
    else     
        printf("%.9lf\n", ans);

    free(count);
    
    return 0;
}

double combin(int n, int r)
{
    double multi = 1;

    if (n < r)
        return 0;
    else {
        while (n > n - r || r >= 1) {
            if (n > n - r) {
                multi *= n;
                n--;
            }

            if (r >= 1) {
                multi /= r;
                r--;
            }
        }
        return multi;
    }
}

double colorPer(int *count, int n, int k)
{
    int sum = 0;
    double numCase = 0;
    int i;

    for (i = 0; i < n; i++) 
        sum += count[i];
    
    for (i = 0; i < n; i++) 
        numCase += combin(count[i], k);
    
    return numCase / combin(sum, k);  
}
