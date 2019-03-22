#include <cstdio>
#include <cstring>
#define max 10001

typedef long long ll
const ll mod = 1000000007;
ll dp[2][max];
int N, h[max];

int main()
{
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", h+i);
        if(h[i] != -1)
            ++h[i]; // 왜 증가시키지???
    }

    int t = 1;
    dp[0][1] = (h[0] == -1 || h[0] == 1) ? 1 : 0; 
    for(int i = 1; i < N; i++, t = 1 - t){ // t를 1과 0으로 왔다갔다 
        memset(dp[t], 0, sizeof(dp[t]));
        if(h[i] == -1){    
            for(int j = 1; j <= N; j++)
                dp[t][j] = (dp[1-t][j-1] + dp[1-t][j] + dp[1-t][j+1]) % mod;
        } else {
            dp[t][h[i]] = (dp[1-t][h[i]-1] + dp[1-t][h[i]] + dp[1-t][h[i]+1]) % mod;
        }
    }
    printf("%lld\n", dp[1-t][1]);
    return 0;
}