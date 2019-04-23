#include <cstdio>
using namespace std;
#define max_N 51

double dp[5001][5001];
int N, M, K, rock[max_N];
double ans;

double comb(int n, int k){
    if(k > n) return 0;
    if(dp[n][k]) return dp[n][k];
    if(n == k) return dp[n][n] = 1;
    if(k == 0) return dp[n][0] = 1;
    dp[n][k] = comb(n-1, k-1) + comb(n-1, k);
    return dp[n][k];
}

int main(){
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &rock[i]);
        N += rock[i];
    }

    scanf("%d", &K);
    double all = comb(N, K);
    for(int i = 0; i < M; i++){
        ans += comb(rock[i], K) / all;
    }
    printf("%.20f\n", ans);
    return 0;
}