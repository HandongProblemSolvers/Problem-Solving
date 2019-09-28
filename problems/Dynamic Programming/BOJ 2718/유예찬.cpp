// baekjoon 2718 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, dp[100];

int dfs(int n)
{
	int &ret = dp[n];
	if (ret) return ret;
	ret += dfs(n-2) + dfs(n-1);
	for (int i=n-2; i>=0; i-=2)
		ret += dfs(i)*3;
	for (int i=n-3; i>=0; i-=2)
		ret += dfs(i)*2;
	return ret;
}

int main()
{
	scanf("%d", &T);
	dp[0]=dp[1]=1;
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dfs(N));
	}
	return 0;
}