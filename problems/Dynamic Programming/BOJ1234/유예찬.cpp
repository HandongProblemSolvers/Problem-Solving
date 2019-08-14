// baekjoon 1234 yechan
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, R, G, B;
ll dp[11][101][101][101];
ll fact[11];

inline ll cm(int n, int c) { return fact[n]/pow(fact[n/c], c); }

ll dfs(int n, int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0) return 0;
	if (n == 0) return 1;

	ll &ret = dp[n][r][g][b];
	if (ret != -1) return ret;

	ret = 0;
	if (n % 3 == 0) {
		ret += cm(n, 3)*dfs(n-1, r-n/3, g-n/3, b-n/3);
	}
	if (n % 2 == 0) {
		ll tmp = cm(n, 2);
		ret += tmp*dfs(n-1, r, g-n/2, b-n/2);
		ret += tmp*dfs(n-1, r-n/2, g, b-n/2);
		ret += tmp*dfs(n-1, r-n/2, g-n/2, b);
	}
	ret += dfs(n-1, r, g, b-n);
	ret += dfs(n-1, r, g-n, b);
	ret += dfs(n-1, r-n, g, b);
	return ret;
};

int main()
{
	fact[0]=fact[1]=1;
	for (int i=2; i<11; i++)
		fact[i] = fact[i-1]*i;
	memset(dp, 0xFF, sizeof(dp));
	scanf("%d%d%d%d", &N, &R, &G, &B);
	printf("%lld\n", dfs(N, R, G, B));
	return 0;
}