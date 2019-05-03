// baekjoon 10217_2 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int MAX_N=101;
const int MAX_K=10001;

int T, N, M, K, ans, u, v, c, d; // cost, delay
int dp[MAX_N][MAX_K]; // [node][money]
vector<vector<pair<pair<int,int>,int> > > adj;
// [[cost, distance], node]
int dfs(int here, int cost) { // current cost
	if (cost > M) return 1e9;
	if (here == N) return 0;
	int &ret = dp[here][cost];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i=0; i<adj[here].size(); i++)
		ret = min(ret, dfs(adj[here][i].second, cost + adj[here][i].first.first) + adj[here][i].first.second);
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &N, &M, &K);
		adj = vector<vector<pair<pair<int,int>,int> > >(N+1);
		for (int i=0; i<K; i++) {
			scanf("%d%d%d%d", &u, &v, &c, &d);
			adj[u].push_back({{c,d}, v});
		}
		for (int i=1; i<=N; i++) 
			sort(adj[i].begin(),adj[i].end());
		ans = dfs(1, 0);
		if (ans==1e9) puts("Poor KCM");
		else printf("%d\n", ans);
	}
	return 0;
}