// baekjoon 2579 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=301;
const int MIN_INF=-1e9;

int N, stair[MAX_N], dp[3][MAX_N];

int dfs(int cnt, int here) {
	if (here > N) return MIN_INF;
	if (here == N) return stair[N];
	int &ret = dp[cnt][here];
	if (ret) return ret;
	ret = 0;
	if (cnt < 2) ret = max(ret, dfs(cnt+1, here+1)+stair[here]);
	ret = max(ret, dfs(1, here+2)+stair[here]);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &stair[i]);
	printf("%d\n", dfs(0, 0));
	return 0;
}