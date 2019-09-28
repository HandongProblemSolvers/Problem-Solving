#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
typedef pair<int, int> P;
typedef long long ll;

int N, L, t, d, uline[MAX_N], dline[MAX_N];
P line[MAX_N];
ll dp[MAX_N][2], ret;

int main() {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &t, &d);
		line[i].first = uline[i] = t;
		line[i].second = dline[i] = d;
	}
	sort(line, line+N);
	sort(uline, uline+N);
	sort(dline, dline+N);
	for (int i=0; i<N; i++) {
		int uidx = lower_bound(uline, uline+N, line[i].first) - uline;
		int didx = lower_bound(dline, dline+N, line[i].second) - dline;
		int len = abs(line[i].first-line[i].second) + L;
		ll pt = dp[uidx][0], pd = dp[didx][1];
		dp[uidx][0] = max(pt, pd + len);
		dp[didx][1] = max(pd, pt + len);
		ret = max(ret, max(dp[uidx][0], dp[didx][1]));
	}
	printf("%lld\n", ret);
	return 0;
}