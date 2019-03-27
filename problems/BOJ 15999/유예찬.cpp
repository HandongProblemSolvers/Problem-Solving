// baekjoon 15999 yechan
#include <cstdio>
#include <algorithm>
using namespace	std;
typedef long long ll;
const int MAX_N=2001;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll DIV_NUM=1000000007;

int N, M;
bool visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];

ll pow(int a, int b) { // a^b
	if (b == 0) return 1;
	ll ret = pow(a, b/2);
	ret = (ret * ret)%DIV_NUM;
	if (b % 2) ret = (ret * a)%DIV_NUM;
	return ret;
}

int dfs(int x, int y) {
	visited[x][y]=false;
	int ret=1;
	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx < 0 || nx >=N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny]) ret += dfs(nx, ny);
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			int around = 0;
			for (int d=0; d<4; d++) {
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
					around++;
					continue;
				}
				if (board[nx][ny] == board[i][j]) {
					around++;
				}
			}
			if (around == 4) {
				visited[i][j]=true;
			}
		}
	}

	int ret =0;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (visited[i][j])
				ret += dfs(i, j);
	printf("%lld\n", pow(2, ret));
	return 0;
}