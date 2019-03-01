#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n;
int dp[505][505];
pii a[505];

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = i==j?0:2e9;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j+i<=n; j++){
            for(int k=j; k<j+i; k++){
                dp[j][j+i] = 
                    min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+a[j].first*a[k].second*a[j+i].second);
            }
        }
    }
    printf("%d",dp[1][n]);

    return 0;
}