// baekjoon 4243 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

const int MAX_N=101;
const ll LL_MAX=(1LL<<62);

int T, N, S;
ll x, sum[MAX_N], dp[2][MAX_N][MAX_N]; // range sum it
// state : [arrow left or right(0,1)][left pos][right pos]
// equation : 
// Except. (left <= 0 || right > N) return LL_MAX;
// Case 1. (left == right) ? return (left == S) ? 0:LL_MAX;
// Case 2. if (arrow == 0) dp[0][left][right] = 
// 				min(dp[0][left+1][right] + sum(left, left+1),
// 					dp[1][left+1][right] + sum(left, right))
// Case 3. if (arrow == 1) dp[1][left][right] =
// 				min(dp[1][left][right-1] + sum(right-1, right),
// 					dp[0][left][right-1] + sum(left, right))

inline ll getSum(int left, int right) { return sum[right]-sum[left]; }

ll dfs(int arrow, int left, int right, int remain)
{
	if (left <= 0 || right > N) return LL_MAX;

	ll &ret = dp[arrow][left][right];
	if (left == right) return (left == S) ? 0 : LL_MAX;

	if (ret) return ret;

	ret = LL_MAX;
	if (arrow == 0)
	{
		ret = min(\
			dfs(0, left+1, right, remain+1) + (remain+1)*getSum(left, left+1),\
			dfs(1, left+1, right, remain+1) + (remain+1)*getSum(left, right)\
		);
	}
	else
	{
		ret = min(\
			dfs(1, left, right-1, remain+1) + (remain+1)*getSum(right-1, right),\
			dfs(0, left, right-1, remain+1) + (remain+1)*getSum(left, right)\
		);
	}

	return ret;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &N, &S);
		// sum[i] = (1 -> i)
		// (i, j) = sum[j] - sum[i] = (1 -> j) - (1 - > i) = (i -> j)
		// (i, i) if (i == S) return 0 : return INF
		for (int i=2; i<=N; i++) {
			scanf("%lld", &x);
			sum[i] = sum[i-1] + x;
		}
		printf("%lld\n", min(dfs(0, 1, N, 0), dfs(1, 1, N, 0)));
	}
	return 0;
}