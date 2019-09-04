// baekjoon 1014 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=10;
const int SIZE=1<<MAX_N;

char str[MAX_N+1];
int T, N, M, dp[MAX_N][SIZE], board[MAX_N];
int cnt[SIZE];

inline bool check(int a, int b) { 
	return ((a & (b * 2)) > 0) || ((a & (b / 2)) > 0);
}

inline bool overlab(int idx, int cur) {
	return ((board[idx] & cur) > 0);
}

int main()
{
	for (int i=0; i<SIZE; i++) {
		if (check(i, i)) continue;
		int tmp = i;
		while (tmp) {
			if (tmp & 1) cnt[i]++;
			tmp >>= 1;
		}
	}

	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		scanf("%d%d", &N, &M);
		for (int i=0; i<N; i++) {
			scanf("%s", str);
			int ans = 0;
			for (int j=0; j<M; j++) {
				ans = ans*2;
				if (str[j] == 'x') ans++;
			}
			board[i] = ans;
		}

		int MSIZE = 1<<M;
		for (int i=0; i<MSIZE; i++) {
			if (overlab(0, i) || check(i, i)) continue;
			dp[0][i]=cnt[i];
		}

		for (int i=1; i<N; i++) {
			for (int j=0; j<MSIZE; j++) {
				if (dp[i-1][j] == -1) continue;
				if (overlab(i-1, j) || check(j, j)) continue;
				for (int k=0; k<MSIZE; k++) {
					if (overlab(i, k) || check(k, k) || check(j, k)) continue;
					dp[i][k] = max(dp[i][k], dp[i-1][j] + cnt[k]);
				}
			}
		}

		for (int i=0; i<MSIZE; i++)
			ret = max(ret, dp[N-1][i]);

		printf("%d\n", ret);
	}
	return 0;
}