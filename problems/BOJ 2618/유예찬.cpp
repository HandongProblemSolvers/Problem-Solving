// baekjoon 2618 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_W=1003;
const ll MAX_INF=(ll)(1e12);
int N, W;
ll dp[MAX_W][MAX_W];
pair<int,int> issue[MAX_W];

inline int getDist(const pair<int,int> &a, const pair<int,int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll dfs(int a, int b) {
	int here = max(a, b)+1;
	int cur_a = (a == -1) ? W : a;
	int cur_b = (b == -1) ? W+1 : b;
	ll &ret = dp[cur_a][cur_b];
	if (here == W) return ret = 0;
	if (ret != -1) return ret;
	ret=MAX_INF;
	// a -> here
	ret=min(ret, dfs(here, b) + getDist(issue[here], issue[cur_a]));
	// b -> here
	ret=min(ret, dfs(a, here) + getDist(issue[here], issue[cur_b]));
	return ret;
}

void tracking(int a, int b) {
	int here = max(a, b)+1;
	if (here == W+1) return;
	int cur_a = (a == -1) ? W : a;
	int cur_b = (b == -1) ? W+1 : b;
	ll cur = dp[cur_a][cur_b];
	if (cur == dp[here][cur_b] + getDist(issue[here], issue[cur_a])) {
		printf("1\n");
		tracking(here, b);
		return;
	}
	if (cur == dp[cur_a][here] + getDist(issue[here], issue[cur_b])) {
		printf("2\n");
		tracking(a, here);
	}
}

int main() {
	scanf("%d%d", &N, &W);
	for (int i=0; i<W+2; i++)
		for (int j=0; j<W+2; j++)
			dp[i][j] = -1;

	for (int i=0; i<W; i++)
		scanf("%d%d", &issue[i].first, &issue[i].second);
	issue[W].first=issue[W].second=1;
	issue[W+1].first=issue[W+1].second=N;

	printf("%lld\n", dfs(-1, -1));
	tracking(-1, -1);
	return 0;
}