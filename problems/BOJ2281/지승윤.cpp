#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[1002][1002];

int main() {
	memset(dp, 100, sizeof(dp)); dp[0][0] = 0;
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1,name; i <= n; i++){
		scanf("%d", &name);
		for (int j = 0; j <= m+1; j++) {
			if (dp[j][i - 1] < dp[1][0]) {
				if (j + name + 1 <= m+1) {
					dp[j + name+1][i] = dp[j][i - 1];
				}
				if (i != 1) {
					dp[name+1][i] = min(dp[name+1][i], dp[j][i - 1] + (m - j+1)*(m - j+1));
				}
			}
		}
	}
	int ans = dp[1][0];
	for (int j = 0; j <= m; j++) {
		ans = min(ans, dp[j][n]);
	}
	printf("%d\n", ans);
	return 0;
}
