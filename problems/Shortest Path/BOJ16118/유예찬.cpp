// baekjoon 16118 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N=4001;
const int MAX_INF=2e9;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;

int N, M;
int dist_y[MAX_N];
int dist_n[2][MAX_N]; // (여우, 늑대)(position)
bool visited_y[MAX_N], visited_n[2][MAX_N];
vector<P> adj[MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		adj[u-1].push_back({v-1, d*2}); // 늑대의 2배 속도를 표현하기 위한 테크닉
		adj[v-1].push_back({u-1, d*2});
	}

	// 여우 >> 속도 일정
	priority_queue<P, vector<P>, greater<P> > PQ_y;
	fill(dist_y, dist_y+MAX_N, MAX_INF);

	dist_y[0]=0;
	PQ_y.push({0, 0}); // start pos (dist, pos)
	while (!PQ_y.empty()) {
		int cur;
		do {
			cur = PQ_y.top().second;
			PQ_y.pop();
		} while (!PQ_y.empty() && visited_y[cur]);
		if (visited_y[cur]) break;
		visited_y[cur]=true;
		for (auto &p: adj[cur]) {
			int next = p.first, d = p.second;
			if (dist_y[next] > dist_y[cur] + d) {
				dist_y[next] = dist_y[cur] + d;
				PQ_y.push({dist_y[next], next});
			}
		}
	}

	// 늑대 >> 속도 불규칙 (홀수 2배, 짝수 1/2배)
	priority_queue<PP, vector<PP>, greater<PP> > PQ_n; // (dist, (count, pos))
	fill(dist_n[0], dist_n[0]+MAX_N, MAX_INF);
	fill(dist_n[1], dist_n[1]+MAX_N, MAX_INF);

	dist_n[0][0]=0;
	PQ_n.push({0, {0, 0}});
	while (!PQ_n.empty()) {
		int cur, cur_c;
		do {
			cur = PQ_n.top().second.second;
			cur_c = PQ_n.top().second.first & 1;
			PQ_n.pop();
		} while (!PQ_n.empty() && visited_n[cur_c][cur]);
		if (visited_n[cur_c][cur]) break;
		visited_n[cur_c][cur]=true;
		for (auto &p: adj[cur]) {
			int next = p.first, d = p.second;
			d = (cur_c) ? d * 2 : d / 2;
			if (dist_n[cur_c ^ 1][next] > dist_n[cur_c][cur] + d) {
				dist_n[cur_c ^ 1][next] = dist_n[cur_c][cur] + d;
				PQ_n.push({dist_n[cur_c ^ 1][next], {cur_c ^ 1, next}});
			}
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		if (dist_y[i] < min(dist_n[0][i], dist_n[1][i])) {
			ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}