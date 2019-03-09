#include<cstring>
#include<cassert>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 1e3;
bool dp[MAX_N+1];

vector<int> G[MAX_N];
vector<int> rG[MAX_N];
bool visited[MAX_N];
stack<int> st;
int gpnum[MAX_N];
int scc_num[MAX_N];

void scc_dfs(int cur) {
	visited[cur] = true;
	for (int next : G[cur])
		if (!visited[next])
			scc_dfs(next);

	st.push(cur);
}

void scc_rdfs(int cur, int curgp) {
	visited[cur] = true;
	gpnum[cur] = curgp;
	scc_num[curgp]++;

	for (int next : rG[cur])
		if (!visited[next])
			scc_rdfs(next, curgp);
}

void make_scc(int N) {
	int curgp = 0;

	memset(visited, 0, sizeof visited);
	for (int i = 0; i < N; i ++)
		if (!visited[i])
			scc_dfs(i);

	memset(visited, 0, sizeof visited);
	while (!st.empty()) {
		int cur = st.top(); st.pop();
		if (!visited[cur]) {
			scc_rdfs(cur, curgp++);
		}
	}
}

int cnt_dfs(int cur) {
	int ret = 1;
	visited[cur] = true;

	for (int next : rG[cur])
		if (!visited[next])
			ret += cnt_dfs(next);

	return ret;
}

int main(void) {
	cin.sync_with_stdio(false), cin.tie(NULL);
	int N, K;	cin >> N >> K;

	int v;
	for (int i = 0; i < N; i ++) {
		cin >> v;
		v--;

		G[i].push_back(v);
		rG[v].push_back(i);
	}

	make_scc(N);
	vector<pair<int, int>> items;

	memset(visited, 0, sizeof visited);
	for (int i = 0; i < N; i ++) 
		if (!visited[i] && gpnum[G[i][0]] == gpnum[i])
			items.emplace_back(scc_num[gpnum[i]], cnt_dfs(i));

	dp[0] = true;
	for (auto it : items) {
		for (int i = K; i >= 0; i --) {
			if (!dp[i])
				continue;

			for (int p = it.first; p <= it.second; p ++)
				if (i+p <= K)
					dp[i+p] = true;
		}
	}

	for (int i = K; i >= 0; i --)
		if (dp[i]) {
			cout << i << endl;
			return 0;
		}

	assert(false);
	return 0;
}