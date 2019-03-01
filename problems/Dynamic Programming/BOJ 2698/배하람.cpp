#include <cstdio>

int tc,n,k;
int dp[101][101][2];

int main(void)
{
    scanf("%d",&tc);

    while(tc--){
        scanf("%d%d",&n,&k);
        dp[1][0][0] = dp[1][0][1] = 1;
        for(int i=2; i<=n; i++){
            dp[i][0][1] = dp[i-1][0][0];
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
            for(int j=1; j<=k; j++){
                dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j][0];
                dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            }
        }

        printf("%d\n",dp[n][k][0]+dp[n][k][1]);
    }

    return 0;
}