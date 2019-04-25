// baekjoon 2494 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=10001;

int N, dp[10][MAX_N];
char S[MAX_N], D[MAX_N];

// here screw and remain turns to left
int dfs(int here, int turns) {
	if (here == N) return dp[turns][here]=0;

	int &ret = dp[turns][here];
	if (ret != -1) return ret;
	ret = 1e9; // init

	int df = (20+((int)(D[here]-'0')-(int)(S[here]-'0'))-turns)%10; // remain to left
	ret = min(ret, dfs(here + 1, (df+turns)%10) + df); // left
	ret = min(ret, dfs(here + 1, turns) + (10-df)%10); // right
	return ret;
}

void backTracking(int here, int turns) {
	if (here == N) return;

	int df = (20+((int)(D[here]-'0')-(int)(S[here]-'0'))-turns)%10; // remain to left
	if (dp[turns][here+1] != -1 && dp[turns][here]-dp[turns][here+1] == (10-df)%10) { // right 로 돌린 경우
		printf("%d %d\n", here+1, -(10-df)%10);
		backTracking(here+1, turns);
	}
	else {
		printf("%d %d\n", here+1, df);
		backTracking(here+1, (10+df+turns)%10);
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	scanf("%s%s", S, D);
	printf("%d\n", dfs(0, 0));
	backTracking(0, 0);
	return 0;
}