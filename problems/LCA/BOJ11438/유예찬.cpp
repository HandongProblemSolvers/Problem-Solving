// baekjoon 11438 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_K=18;
const int MAX_N=100001;

int N, M;
int parent[MAX_N][MAX_K];
int depth[MAX_N];
vector<int> connect[MAX_N];

void makeTreeByDFS(int curr) {
	for (int i=0; i < connect[curr].size(); i++)
	{
		int next = connect[curr][i];
		if (depth[next] == -1) {
			depth[next] = depth[curr] + 1;
			parent[next][0] = curr;
			makeTreeByDFS(next);
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));

	depth[0]=0;
	makeTreeByDFS(0);
	// parent[i][j+1] = parent[ parent[i][j] ][j] >> parent[i][j+1] >> 2^(j+1) depth diffence
	for (int j=0; j<MAX_K-1; j++)
		for (int i=1; i<N; i++)
			if (parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];

	scanf("%d", &M);
	for (int i=0; i<M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;

		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		// bottom up 'node u'
		for (int j=0; diff; j++)
		{
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		// same depth u and v >> ride up same util parent(u) == parent(v)
		if (u != v)
		{
			for (int j=MAX_K-1; j>=0; j--)
			{
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}

		printf("%d\n", u+1);
	}

	return 0;
}