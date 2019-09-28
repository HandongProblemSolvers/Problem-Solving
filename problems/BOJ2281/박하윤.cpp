// DP_데스노트_2281

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, len[1001];
int dp[1001][1001];

// col = 현재 열, cnt = 현재 이름의 인덱스+1
int solve(int col, int cnt){
  // 모든 이름을 다 기재했을 경우
  if(cnt == n) return 0;
  // 해당 열을 꽉 채워 쓰거나 한 칸만 남은 경우
  if(col >= m) return solve(len[cnt]+1, cnt+1) + (col == m? 1:0);
  // meomoization
  int &ret = dp[col][cnt];
  if(ret != -1) return ret;
  // 남은 여백의 칸수 제곱을 더함
  ret = solve(len[cnt]+1, cnt+1) + (m-col+1)*(m-col+1);
  // 해당 줄에 이어서 쓸 수 있을 경우
  if(col+len[cnt] <= m) ret = min(ret, solve(col+len[cnt]+1, cnt+1));
  return ret;
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &len[i]);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(len[0]+1, 1));
  return 0;
}
