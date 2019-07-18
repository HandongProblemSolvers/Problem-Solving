// baekjoon 11562 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N=251;

int N, M, u, v, b, K, s, e;
int adj[MAX_N][MAX_N];

int main() {
	memset(adj, -1, sizeof(adj));
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++) adj[i][i]=0;

	while (M--) {
		scanf("%d%d%d", &u, &v, &b);
		adj[u][v]=0;
		adj[v][u]=!b;
	}

	for (int k=1; k<=N; k++) {
		for (int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if (i == j) continue;
				if (adj[i][k] == -1 || adj[k][j] == -1) continue;
				if (adj[i][j] == -1 || (adj[i][j] > adj[i][k] + adj[k][j]))
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	scanf("%d", &K);
	while (K--) {
		scanf("%d%d", &s, &e);
		printf("%d\n", adj[s][e]);
	}
	return 0;
}
