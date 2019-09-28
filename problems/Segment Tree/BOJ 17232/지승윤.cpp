#include <bits/stdc++.h>
using namespace std;

int N, M, T, K, a, b;
char mp[101][101], mpc[101][101];
int judge(int x, int y) {
	int cnt = 0;
	for (int i = -K; i <= K; i++) {
		for (int j = -K; j <= K; j++) {
			if (i == 0 && j == 0) continue;
			if (x + i > N || x + i < 1 || y + j > M || y + j < 1) continue;
			if (mp[x + i][y + j] == '*') cnt++;
		}
	}
	return cnt;
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = judge(i, j);
			if (mp[i][j] == '*') {
				if (tmp >= a && tmp <= b) mpc[i][j] = '*';
				else mpc[i][j] = '.';
			}
			else if (mp[i][j] == '.') {
				if (tmp > a && tmp <= b) mpc[i][j] = '*';
				else mpc[i][j] = '.';
			}
		}
	}
	memcpy(mp, mpc, sizeof(char)*101*101);
	memset(mpc, 0, sizeof(mpc));
}
int main() {
	cin >> N >> M >> T >> K >> a >> b;
	for (int i = 1; i <= N; i++)
			scanf("%s", mp[i] + 1);
	for (int i = 0; i < T; i++) {
		solve();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%c", mp[i][j]);
		}
		printf("\n");
	}
}
