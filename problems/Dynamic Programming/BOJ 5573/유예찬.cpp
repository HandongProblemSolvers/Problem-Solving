// baekjoon 5573 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_W=1001;

int W, H, x, cnt, dp[MAX_W][MAX_W][2], px, py;
// dp[height][width][status], status(0:1=down:right)

int main() {
	scanf("%d%d%d",&H,&W,&dp[0][1][0]);
	px=py=1;
	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			scanf("%d", &x);
			cnt = dp[i-1][j][0]+dp[i][j-1][1];
			dp[i][j][0]=(cnt+(x^1))/2;
			dp[i][j][1]=(cnt+(x&1))/2;
			if (px==i && py==j) {
				x = (cnt+x)&1;
				px=px+x;
				py=py+(!x);
			}
		}
	}
	printf("%d %d\n",px,py);
	return 0;
}