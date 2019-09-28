// baekjoon 1028 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_R=752;

int R, C, dp[2][MAX_R][MAX_R];
char mine[MAX_R][MAX_R];

int main()
{
	scanf("%d%d", &R, &C);
	for (int i=1; i<=R; i++)
		scanf("%s", mine[i]+1);

	for (int i=R; i>=1; i--)
		for (int j=C; j>=1; j--)
			if (mine[i][j] == '1') {
				dp[0][i][j] = dp[0][i+1][j+1] + 1; // (left up arrow)
				dp[1][i][j] = dp[1][i+1][j-1] + 1; // (right up arrow)
			}

	int ret=0;
	for (int i=1; i<=R; i++)
		for (int j=1; j<=C; j++)
			for (int k=min(dp[0][i][j], dp[1][i][j]); k > ret; k--)
				if (min(dp[0][i+k-1][j-k+1], dp[1][i+k-1][j+k-1]) >= k)
					ret = k;

	printf("%d\n", ret);
	return 0;
}