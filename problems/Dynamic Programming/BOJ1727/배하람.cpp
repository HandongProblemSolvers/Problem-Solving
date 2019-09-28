#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int SIZE = 1001;
int n,m;
int male[SIZE],female[SIZE];
int dp[SIZE][SIZE];

int main(void)
{
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++) scanf("%d",&male[i]);
  for(int i=1; i<=m; i++) scanf("%d",&female[i]);

  // 여자쪽을 항상 많게 만들어준다.
  if(n>m){
    swap(male,female);
    swap(n,m);
  }

  sort(male,male+1+n);
  sort(female,female+1+m);

  // 1번째 남자에 대한 경우 초기화
  dp[1][1] = abs(male[1]-female[1]);
  for(int i=2; i<=m-n+1; i++) 
    dp[1][i] = min(dp[1][i-1],abs(male[1]-female[i]));

  // 2번째 남자부터 점화식으로 계산
  for(int i=2; i<=n; i++){
    dp[i][i] = dp[i-1][i-1] + abs(male[i]-female[i]);
    for(int j=i+1; j<=m-n+i; j++) 
      dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(male[i]-female[j]));
  }
  
  printf("%d\n",dp[n][m]);
  return 0;
}