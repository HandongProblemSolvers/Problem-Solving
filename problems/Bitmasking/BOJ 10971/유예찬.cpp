// baekjoon 10971 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=10;
const int SIZE=1<<MAX_N;
int N, W[MAX_N][MAX_N], dp[SIZE][MAX_N];

int dfs(int here, int state) {
	if (state == (1<<N)-1) return W[here][0] ? W[here][0] : 1e9;
	int &ret = dp[state][here];
	if (ret) return ret;
	ret = 1e9;
	for (int i=0; i<N; i++)
		if (W[here][i] && !((state>>i) & 1))
			ret = min(ret, dfs(i, state|(1<<i))+W[here][i]);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) for (int j=0; j<N; j++)
		scanf("%d", &W[i][j]);

	printf("%d",dfs(0,1));
	return 0;
}