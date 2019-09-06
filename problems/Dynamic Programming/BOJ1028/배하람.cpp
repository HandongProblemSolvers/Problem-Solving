#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mine[751][751];
int dp[751][751][5];
int R,C;
char s[752];

int f(int row, int col, int dir)
{
  if(row < 1 || row > R || col < 1 || col > C) return 0;
  int &ret = dp[row][col][dir];
  if(ret != -1) return ret;
  ret = mine[row][col];
  if(ret) {
    switch(dir){
      case 1: ret += f(row-1, col+1, dir); break;
      case 2: ret += f(row+1, col+1, dir); break;
      case 3: ret += f(row-1, col-1, dir); break;
      case 4: ret += f(row+1, col-1, dir);
    }
  }
  return ret;
}

int solve()
{
  int ans = 0;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      int kMax = min(dp[i][j][1],dp[i][j][2]);
      for(int k=1; k<=kMax; k++){
        int right = j + k*2 - 2;
        if(right < 1 || right > C) continue;
        if(min(dp[i][right][3],dp[i][right][4]) >= k)
          ans = max(ans, k);
      }
    }
  }
  return ans;
}

int main(void)
{
  scanf("%d%d", &R,&C);
  for(int i=1; i<=R; i++){
    scanf("%s", &s[1]);
    for(int j=1; j<=C; j++){
      mine[i][j] = s[j] - '0';
    }
  }
  memset(dp,-1,sizeof(dp));
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      f(i,j,1); f(i,j,2);
      f(i,j,3); f(i,j,4);
    }
  }
  printf("%d\n",solve());
  return 0;
}