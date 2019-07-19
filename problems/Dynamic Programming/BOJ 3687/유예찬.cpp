// baekjoon 3687 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=101;
const ll MAX_INF=(1LL)<<52;

int T, N;
int gebi[10] =     {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool visited[10] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0};
ll dp[MAX_N];

void printMax(int here) {
	if (here % 2 == 1) printf("7");
	else printf("1");
	for (int i=1; i<here/2; i++)
		printf("1");
	puts("");
}

ll dfs(int here) {
	if (here == 0) return 0;
	if (here == 1) return MAX_INF;
	ll &ret = dp[here];
	if (ret != -1) return ret;
	ret = MAX_INF;
	if (gebi[0] < here) ret = min(ret, 10*dfs(here-gebi[0]));
	for (int i=1; i<10; i++) {
		if (!visited[i]) continue;
		if (gebi[i] <= here) ret = min(ret, i+10*dfs(here-gebi[i]));
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	fill(dp, dp+MAX_N, -1);
	while (T--) {
		scanf("%d", &N);
		printf("%lld ", dfs(N));
		printMax(N);
	}
	return 0;
}