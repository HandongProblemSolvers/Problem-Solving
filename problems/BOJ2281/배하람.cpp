#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 1000;
const int INF = 2e9;
int note[SIZE+1][SIZE+1];
int dp[SIZE+1][SIZE+1];
int people[SIZE+1],sum[SIZE+1];
int N,M;

int f(int row, int nth)
{
  if(nth > N) return INF;
  int &ret = dp[row][nth];
  if(ret != -1) return ret;

  ret = INF;
  for(int i=nth; i<=N; i++){
    int ret2 = (i - nth) + (sum[i] - sum[nth-1]);
    if(ret2 > M) continue;
    ret2 = M - ret2;
    int fret = f(row+1, i+1);
    if(fret == INF) return ret = 0;
    ret = min(ret, ret2*ret2 + fret);
  }
  return ret;
}

int main(void)
{
  scanf("%d%d", &N,&M);
  for(int i=1; i<=N; i++) {
    scanf("%d", &people[i]);
    sum[i] = people[i];
  }
  for(int i=2; i<=N; i++) sum[i] += sum[i-1];
  memset(dp, -1, sizeof(dp));
  printf("%d\n", f(1,1));
  return 0;
}