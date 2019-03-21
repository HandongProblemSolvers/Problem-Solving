// baekjoon 1699 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, dp[100001];
int main() {
	memset(dp, 0x3c, sizeof(dp));
	scanf("%d", &N);
	dp[0]=0;
	for (int i=1; i<=N; i++) for (int j=1; j*j<=i; j++)
		dp[i] = min(dp[i], dp[i-j*j]+1);
	printf("%d\n", dp[N]);
	return 0;
}