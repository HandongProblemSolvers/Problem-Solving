// baekjoon 1146 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX_N=100;
const int MOD=1e6;

int N, dp[MAX_N][MAX_N][2];

int dfs(int lnum, int rnum, bool arrow) {
	int &ret = dp[lnum][rnum][arrow];
	if (ret != -1) return ret;
	if (!lnum && !rnum) return ret = 1;

	ret = 0;
	if (arrow) {
		for (int i=0; i<lnum; i++)
			ret = (ret + dfs(i, lnum+rnum-i-1, false))%MOD;
	}
	else {
		for (int i=0; i<rnum; i++)
			ret = (ret + dfs(lnum+rnum-i-1, i, true))%MOD;
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	if (N == 1)
		return !printf("1\n");
	int ret = 0;
	for (int i=0; i<N; i++) {
		ret = (ret + dfs(i, N-i-1, false)) % MOD;
		ret = (ret + dfs(i, N-i-1, true)) % MOD;
	}
	printf("%d\n", ret);
	return 0;
}