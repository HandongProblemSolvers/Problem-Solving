//BOJ13251 조약돌꺼내기
#include <cstdio>
using namespace std;
#define MAX_N 2501
int M, K, N, st[51];
double dp[MAX_N][MAX_N], ans;

double comb(int n, int k) {
	if (k > n) return 0;
	if (dp[n][k]) return dp[n][k];
	if (n == k) return dp[n][n] = 1;
	if (k == 0) return dp[n][0] = 1;
	dp[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
	return dp[n][k];
}

int main() {
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		scanf("%d", &st[i]);
		N += st[i];
	}
	scanf("%d", &K);

	double d = comb(N, K);
	for (int i = 0; i < M; i++) {
		ans += comb(st[i], K) / d;
	}
	printf("%0.20f", ans);

	return 0;
}
