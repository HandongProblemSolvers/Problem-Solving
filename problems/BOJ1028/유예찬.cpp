// baekjoon 1028 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_R=752;
const int dir[2][2] = {{-1, 1}, {-1, -1}};

char str[MAX_R];
int R, C, mine[MAX_R][MAX_R];
int dp[2][MAX_R][MAX_R];

int main()
{
	scanf("%d%d", &R, &C);
	for (int i=1; i<=R; i++) {
		scanf("%s", str+1);
		for (int j=1; j<=C; j++) {
			mine[i][j] = str[j]-'0';
		}
	}

	for (int d=0; d<2; d++)
		for (int i=1; i<=R; i++)
			for (int j=1; j<=C; j++)
				if (mine[i][j])
					dp[d][i][j] = dp[d][i+dir[d][0]][j+dir[d][1]] + 1;

	// i + 1 = size of dia
	// min(dp(0, x+i, y), dp(0, x+i*2, y+i), dp(1, x+i*2, y+i), dp(1, x+i, y+i*2)) >= i, dia size is bigger than 'i'
	int ret=0;
	for (int i=0; i*2+1<=min(R,C); i++)
		for (int x=1; x+2*i<=R; x++)
			for (int y=1; y+2*i<=C; y++)
				if (min(dp[0][i+x][y], min(dp[0][i*2+x][i+y], min(dp[1][i*2+x][i+y], dp[1][i+x][i*2+y]))) >= i+1)
					ret = max(ret, i+1);

	printf("%d\n", ret);
	return 0;
}