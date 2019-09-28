#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int stair[301],dp[301][3];

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&stair[i]);

    dp[1][1] = stair[1];
    for(int i=2; i<=n; i++){
        dp[i][1] = max(dp[i-2][1],dp[i-2][2]) + stair[i];
        dp[i][2] = dp[i-1][1] + stair[i];
    }

    printf("%d\n",max(dp[n][1],dp[n][2]));

    return 0;
}