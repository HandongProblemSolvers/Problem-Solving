// baekjoon 2178_2 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=101;
const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int N, M;
char miro[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int bfs(void) {
	queue<pair<int, int>> q;
	q.push({0,0});
	visited[0][0]=true;
	int depth=1;
	while (!q.empty()) {
		int qSize=q.size();
		while (qSize--) {
			int cur_x=q.front().first;
			int cur_y=q.front().second;
			q.pop();
			if (cur_x == N-1 && cur_y == M-1) return depth;
			for (int d=0; d<4; d++) {
				int nx=cur_x+dir[d][0];
				int ny=cur_y+dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (visited[nx][ny]) continue;
				if (miro[nx][ny]=='0') continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", miro[i]);
	printf("%d\n", bfs());
	return 0;
}