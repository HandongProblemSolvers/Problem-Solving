#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

struct infor {
	int target, cost, time;
	bool operator < (const infor & a) const {
		return time > a.time;
	}
};

int test, n, m, k, u, v, c, d;
int D[101][10001];
int record[101][10001];

vector<infor> adj[101];


int main() {
	
	scanf("%d", &test);

	while (test--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			adj[u].push_back({ v, c, d });
		}
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= m; j++) 
				D[i][j] = INF;

		priority_queue<infor> queue;
		queue.push({ 1, m, 0 });
		D[1][m] = 0;

		while (!queue.empty()) {
			infor tmp = queue.top();
			queue.pop();
			int v = tmp.target;
			int w = tmp.cost;
			int p = tmp.time;

			if (v != 1 && D[v][w] <= p)
				continue;
			D[v][w] = p;

			if (v == n) break;

			for (int i = 0; i < adj[v].size(); i++) {
				if (w - adj[v][i].cost >= 0 && D[adj[v][i].target][w - adj[v][i].cost] > D[v][w] + adj[v][i].time)
					queue.push({ adj[v][i].target, w - adj[v][i].cost, D[v][w] + adj[v][i].time });
			}
		}

		int ans = INF;

		for (int i = 0; i <= m; i++) 
			ans = min(ans, D[n][i]);
		if (ans == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", ans);

		for (int i = 0; i <= n; i++)
			adj[i].clear();
	
		
	}
}