// baekjoon 2300 yechan
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N=10001;

int N, x, y, dp[MAX_N];
pair<int,int> point[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d%d", &x, &y);
		point[i] = {x, abs(y)};
	}
	sort(point+1, point+1+N);

	for (int i=1; i<=N; i++) {
		int h = point[i].second;
		dp[i] = dp[i-1] + h*2;
		for (int j=i-1; j>0; j--) {
			h = max(h, point[j].second);
			dp[i] = min(dp[i], max(h*2, point[i].first - point[j].first) + dp[j-1]);
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}