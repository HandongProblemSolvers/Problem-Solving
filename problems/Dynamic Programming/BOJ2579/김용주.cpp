//BOJ2579 계단오르기
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 301

int N, stair[MAX_N], dp[MAX_N][3];

int upstair(int n, int state){
    if(n > N) return -1;
    if(n == N) return stair[N];
    int &ret = dp[n][state];
    if(ret) return ret;

    if(state < 2) ret = max(ret, upstair(n + 1, state + 1) + stair[n]);
    ret = max(ret, upstair(n + 2, 1) + stair[n]);
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &stair[i]);
    }

    printf("%d\n", upstair(0, 0));

    return 0;
}