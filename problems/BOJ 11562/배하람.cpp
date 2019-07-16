#include <cstdio>
#include <algorithm>

int dp[251][251];
int n,m,u,v,b,k,s,e;

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            dp[i][j] = 2e6;
        }
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&u,&v,&b);
        if(b==0) {
            dp[u][v] = 0;
            dp[v][u] = 1;
        } else {
            dp[u][v] = 0;
            dp[v][u] = 0;
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&s,&e);
        printf("%d\n",dp[s][e]);
    }
    return 0;
}