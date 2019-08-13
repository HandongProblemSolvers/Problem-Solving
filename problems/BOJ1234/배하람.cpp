#include <cstdio>
#include <cstring>

typedef long long ll;

int N,R,G,B;
ll dp[101][101][101];
ll ff[11];

ll f(int n, int r, int g, int b)
{
  if(n == 0) return 1;
  ll &ret = dp[r][g][b];
  if(ret != -1) return ret;

  ret = 0;

  // 단색
  if(r>=n) ret += f(n-1,r-n,g,b);
  if(g>=n) ret += f(n-1,r,g-n,b);
  if(b>=n) ret += f(n-1,r,g,b-n);

  // 짝수
  if(n%2 == 0) {
    if(r>=n/2 && g>=n/2) 
      ret += (ff[n]/ff[n/2]/ff[n/2])*f(n-1,r-n/2,g-n/2,b);
    if(g>=n/2 && b>=n/2) 
      ret += (ff[n]/ff[n/2]/ff[n/2])*f(n-1,r,g-n/2,b-n/2);
    if(r>=n/2 && b>=n/2) 
      ret += (ff[n]/ff[n/2]/ff[n/2])*f(n-1,r-n/2,g,b-n/2);
  }

  // 3의 배수
  if(n%3 == 0) {
    if(r>=n/3 && g>=n/3 && b>=n/3)
      ret += (ff[n]/ff[n/3]/ff[n/3]/ff[n/3])*f(n-1,r-n/3,g-n/3,b-n/3);
  }

  return ret;
}

int main(void)
{
  scanf("%d%d%d%d",&N,&R,&G,&B);
  memset(dp,-1,sizeof(dp));
  ff[0] = ff[1] = 1;
  for(int i=2; i<=N; i++) ff[i] = ff[i-1]*i;
  printf("%lld",f(N,R,G,B));
  return 0;
}