#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define MAX_NUM 31622
#define MAX_SIZE 8

int sieve(int *prime, int *isPrime, int n);
int primeDiv(int *div, int *prime, int n, int x);
long long coprime(int *prime, int n, long long s, long long e, int x);
long long IEP(int *div, int n, long long s, long long e, int x);

int main()
{
    int *prime, *isPrime;
    int T;
    long long A, B; 
    int N;
    int size;

    prime = (int *) malloc((MAX_NUM + 1) * sizeof(int));
    isPrime = (int *) malloc((MAX_NUM + 1) * sizeof(int));
    
    size = sieve(prime, isPrime, MAX_NUM + 1);
    
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%lld %lld %d", &A, &B, &N);
        printf("Case #%d: %lld\n", i + 1, coprime(prime, size, A, B, N));
    }
    free(prime);
    free(isPrime);

    return 0;
}

int sieve(int *prime, int *isPrime, int n)
{
    int count = 0;
    
    isPrime[0] = 0;
    
    for (int i = 1; i < n; i++) 
        isPrime[i] = 1;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            prime[count++] = i;
            
            if (i <= sqrt(n - 1)) {
                for (int j = 2 * i; j < n; j += i) 
                    isPrime[j] = 0;
            }
        }
    }
    return count;
}

int primeDiv(int *div, int *prime, int n, int x)
{
    int num = x;
    int count = 0;

    for (int i = 0; i < n && prime[i] <= x; i++) {
        if (!(x % prime[i])) {
            div[count++] = prime[i];
            
            while (!(num % prime[i]))
                num /= prime[i];
        }
    }

    if (num != 1)
        div[count++] = num;

    return count;
}

long long IEP(int *div, int n, long long s, long long e, int x)
{
    long long *sum;
    long long result = 0;

    sum = (long long *) malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++)
        sum[i] = 0;

    for (int i = 0; i < n; i++) {
        sum[0] += e / div[i] - (s - 1) / div[i];

        for (int j = i + 1; j < n; j++) {
            sum[1] += e / (div[i] * div[j]) - (s - 1) / (div[i] * div[j]);

            for (int k = j + 1; k < n; k++) {
                sum[2] += e / (div[i] * div[j] * div[k]) - (s - 1) / (div[i] * div[j] * div[k]);

                for (int l = k + 1; l < n; l++) { 
                    sum[3] += e / (div[i] * div[j] * div[k] * div[l]) - (s - 1) / (div[i] * div[j] * div[k] * div[l]);

                    for (int m = l + 1; m < n; m++) { 
                        sum[4] += e / (div[i] * div[j] * div[k] * div[l] * div[m]) - (s - 1) / (div[i] * div[j] * div[k] * div[l] * div[m]);

                        for (int o = m + 1; o < n; o++) { 
                            sum[5] += e / (div[i] * div[j] * div[k] * div[l] * div[m] * div[o]) - (s - 1) / (div[i] * div[j] * div[k] * div[l] * div[m] *div[o]);

                            for (int p = o + 1; p < n; p++) { 
                                sum[6] += e / (div[i] * div[j] * div[k] * div[l] * div[m] * div[o] * div[p]) - (s - 1) / (div[i] * div[j] * div[k] * div[l] * div[m] * div[o] * div[p]);

                                for (int q = p + 1; q < n; q++) 
                                    sum[7] += e / (div[i] * div[j] * div[k] * div[l] * div[m] * div[o] * div[p] * div[q]) - (s - 1) / (div[i] * div[j] * div[k] * div[l] * div[m] * div[o] * div[p] * div[q]);
                            }
                        }
                    }
                }
            }
        }
    }       
    
    /*  
    for (int i = 0; i < n; i++) 
        printf("%lld ", sum[i]);
    putchar('\n');
    */
    
    for (int i = 0; i < n; i++)
        result += i % 2 ? -sum[i] : sum[i];

    free(sum);

    return result;    
}

long long coprime(int *prime, int n, long long s, long long e, int x)
{
    int *div;
    int size;
    long long ans = 1;

    div = (int *) malloc(MAX_SIZE * sizeof(int));
    
    size = primeDiv(div, prime, n, x);

    /*   
    for (int i = 0; i < size; i++) 
        printf("%d ", div[i]);
    putchar('\n');    
    */

    ans = IEP(div, size, s, e, x);

    free(div);

    return e - s + 1 - ans;
}

