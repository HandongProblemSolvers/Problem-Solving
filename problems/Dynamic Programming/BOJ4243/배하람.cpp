#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int tc,n,a;
ll sum[101];
ll dp[101][101][2];

/* 전명우님 코드 공부, https://blog.myungwoo.kr/37?category=526554 */

int main(void)
{
  scanf("%d",&tc);
  while(tc--) {
    scanf("%d%d",&n,&a);
    // ti가 pi~pj로 정의되니까 t(i+1)로 정의를 바꿔서 편하게 계산
    for(int i=2; i<=n; i++) scanf("%lld", &sum[i]);
    for(int i=3; i<=n; i++) sum[i] += sum[i-1];
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        dp[i][j][0] = dp[i][j][1] = 2e18;
      }
    }

    dp[a][a][0] = dp[a][a][1] = 0;
    // i는 간격 : pi~pj
    for(int i=1; i<=n; i++){
      // s는 시작지점
      for(int s=1; s<=n-i+1; s++){
        // e는 도착지점
        int e = s+i-1;
        // r은 방문해야 할 나머지 상점 개수
        int r = n-e+s-1;
        // s~e 방문했고 왼쪽에 있을 때 왼쪽/오른쪽으로 이동하는 경우
        if(dp[s][e][0] != 2e18) {
          if(s > 1 && dp[s-1][e][0] > dp[s][e][0] + r * (sum[s] - sum[s-1]))
            dp[s-1][e][0] = dp[s][e][0] + r * (sum[s] - sum[s-1]);
          if(e < n && dp[s][e+1][1] > dp[s][e][0] + r * (sum[e+1] - sum[s]))
            dp[s][e+1][1] = dp[s][e][0] + r * (sum[e+1] - sum[s]);
        }
        // s~e 방문했고 오른쪽에 있을 때 왼쪽/오른쪽으로 이동하는 경우
        if(dp[s][e][1] != 2e18) {
          if(s > 1 && dp[s-1][e][0] > dp[s][e][1] + r * (sum[e] - sum[s-1]))
            dp[s-1][e][0] = dp[s][e][1] + r * (sum[e] - sum[s-1]);
          if(e < n && dp[s][e+1][1] > dp[s][e][1] + r * (sum[e+1] - sum[e]))
            dp[s][e+1][1] = dp[s][e][1] + r * (sum[e+1] - sum[e]);
        }
      }
    }
    printf("%lld\n", min(dp[1][n][0], dp[1][n][1]));
  }
  return 0;
}