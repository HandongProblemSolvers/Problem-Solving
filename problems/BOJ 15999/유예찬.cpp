// baekjoon 15999 yechan
#include <cstdio>
#include <algorithm>
using namespace	std;
typedef long long ll;
const int MAX_N=2001;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll DIV_NUM=1000000007;

int N, M, around, nx, ny, i, j, d, ans;
char board[MAX_N][MAX_N];

ll pow(int a, int b) { // a^b
	if (b == 0) return 1;
	ll ret = pow(a, b/2);
	ret = (ret * ret) % DIV_NUM;
	if (b % 2) ret = (ret * a) % DIV_NUM;
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (i=0; i<N; i++) scanf("%s", board[i]);

	for (i=0; i<N; i++) {
		for (j=0; j<M; j++) {
			around = 0;
			for (d=0; d<4; d++) {
				nx = i + dir[d][0];
				ny = j + dir[d][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) around++;
				else if (board[nx][ny] == board[i][j]) around++;
			}
			if (around == 4) ans++;
		}
	}
	printf("%lld\n", pow(2, ans));
	return 0;
}