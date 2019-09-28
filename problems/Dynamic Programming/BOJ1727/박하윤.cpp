#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int men[1001], women[1001];
int dp[1001][1001];

int match(){
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      dp[i][j] = dp[i-1][j-1] + abs(women[i-1] - men[j-1]);
      if(i > j) dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if(i < j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }
    return dp[n][m];
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", women+i);

  for(int i = 0; i < m; i++)
    scanf("%d", men+i);

  sort(women, women+n);
  sort(men, men+m);

  printf("%d\n", match());
  return 0;

}
