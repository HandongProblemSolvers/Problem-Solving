#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int TC,N,M;
int dp[11][1<<10];
int r[11][11],rr[11],rrr[11];
char room[11][11];

int f(int row, int state)
{
  if(row > N) return 0;
  int &ret = dp[row][state];
  if(ret != -1) return ret;
  ret = 0;

  int temp = state;
  for(int i=M; i>=1; i--){
    r[row-1][i] = temp % 2;
    temp /= 2;
  }

  for(int i=0; i<=(int)pow(2,M)-1; i++){
    int temp = i;
    for(int j=M; j>=1; j--){
      rr[j] = temp % 2;
      temp /= 2;
    }
    bool isPossible = true;
    for(int j=1; j<=M; j++){
      bool leftUp = (j==1 ? 0 : r[row-1][j-1]) && rr[j];
      bool rightUp = (j==M ? 0 : r[row-1][j+1]) && rr[j];
      bool left = (j==1 ? 0 : rr[j-1]) && rr[j];
      bool right = (j==M ? 0 : rr[j+1]) && rr[j];
      bool isNotValid = room[row][j]=='x' && rr[j];
      if(leftUp || rightUp || left || right || isNotValid){
        isPossible = false;
        break;
      }
    }
    if(!isPossible) continue;
    int ret2 = 0;
    for(int j=1; j<=M; j++) ret2 += rr[j];
    ret = max(ret, ret2 + f(row+1, i));
  }
  return ret;
}

int main(void)
{
  scanf("%d", &TC);
  for(int t=1; t<=TC; t++){
    scanf("%d%d", &N,&M);
    for(int i=1; i<=N; i++) scanf("%s", &room[i][1]);
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=0; i<=(int)pow(2,M)-1; i++) {
      int temp = i;
      for(int j=M; j>=1; j--){
        rrr[j] = temp % 2;
        temp /= 2;
      }
      bool isPossible = true;
      for(int j=1; j<=M; j++){
        bool left = (j==1 ? 0 : rrr[j-1]) && rrr[j];
        bool right = (j==M ? 0 : rrr[j+1]) && rrr[j];
        bool isNotValid = room[1][j]=='x' && rrr[j];
        if(left || right || isNotValid){
          isPossible = false;
          break;
        }
      }
      if(!isPossible) continue;
      int ret = 0;
      for(int j=1; j<=M; j++) ret += rrr[j];
      ans = max(ans, ret + f(2,i));
    }
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}