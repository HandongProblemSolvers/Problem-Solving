// baekjoon 2842 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAX_N=51;
const int dir[8][2]={{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int N, totalNode, height[MAX_N][MAX_N], sx, sy, ret=1e6;
vector<int> src;

char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool judge(int &nx, int &ny, int &bottom, int &top) {
	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return true;
	if (visited[nx][ny]) return true;
	if (height[nx][ny] < bottom) return true;
	if (height[nx][ny] > top) return true;
	return false;
}

bool bfs(int bottom, int top) {
	if (height[sx][sy] < bottom || top < height[sx][sy]) return false;
	memset(visited, 0, sizeof(visited));

	int cx, cy, nodeCnt=0;
	queue<P> q;
	q.push(P(sx, sy));
	visited[sx][sy] = true;

	while (!q.empty()) {
		tie(cx, cy) = q.front(); q.pop();
		for (int d=0; d<8; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			if (judge(nx, ny, bottom, top)) continue;
			if (board[nx][ny] == 'K') nodeCnt++;
			visited[nx][ny]=true;
			q.push(P(nx, ny));
		}
		if (nodeCnt == totalNode) return true;
	}
	return (nodeCnt == totalNode);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf(" %s", board[i]);
		for (int j=0; j<N; j++) {
			if (board[i][j] == 'P') sx = i, sy = j;
			if (board[i][j] == 'K') totalNode++;
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf(" %d", &height[i][j]);
			src.push_back(height[i][j]);
		}
	}

	sort(src.begin(), src.end());
	src.erase(unique(src.begin(), src.end()), src.end());

	int sSize=src.size();
	for (int i=0; i<sSize; i++) {
		int left=i, right=sSize-1;
		while (left <= right) {
			int mid = (right + left)/2;
			if (bfs(src[i], src[mid])) right=mid-1, ret=min(ret, src[mid] - src[i]);
			else left=mid+1;
		}
	}
	printf("%d\n", ret);
	return 0;
}