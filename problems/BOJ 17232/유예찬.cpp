// baekjoon 17232 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=102;

int N, M, T, K, a, b;
int dp[MAX_N][MAX_N];
char board[MAX_N][MAX_N];

int main() {
	scanf("%d%d%d", &N, &M, &T);
	scanf("%d%d%d", &K, &a, &b);
	for (int i=1; i<=N; i++) 
		scanf("%s", board[i] + 1);

	while (T--) {
		for (int i=1; i<=N; i++)
			for (int j=1; j<=M; j++)
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (board[i][j] == '*');

		for (int i=1; i<=N; i++) {
			for (int j=1; j<=M; j++) {
				int up = max(0, i-K-1), down = min(N, i+K), left = max(0, j-K-1), right = min(M, j+K);
				int life = dp[down][right] - dp[down][left] - dp[up][right] + dp[up][left] - (board[i][j] == '*');
				if (board[i][j] == '*') {
					if (life < a || life > b) board[i][j] = '.';
				}
				else {
					if (a < life && life <= b) board[i][j] = '*';
				}
			}
		}
	}
	for (int i=1; i<=N; i++)
		printf("%s\n", board[i] + 1);
	return 0;
}