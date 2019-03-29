//BOJ 8984
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_N 100001

int N, L;
ll dp[MAX_N][2], ans;
vector<pair<ll, ll> >	line;
vector<ll> tp, bt;

int main() {
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		int m, n;
		scanf("%d %d", &m, &n);
		line.push_back(make_pair(m, n));
		tp.push_back(m);
		bt.push_back(n);
	}
	sort(line.begin(), line.end());
	sort(tp.begin(), tp.end());
	sort(bt.begin(), bt.end());

	for (int i = 0; i < N; i++) {
		ll up = lower_bound(tp.begin(), tp.end(), line[i].first) - tp.begin();
		ll down = lower_bound(bt.begin(), bt.end(), line[i].second) - bt.begin();
		ll len = L + abs(line[i].first - line[i].second);
		ll t = dp[up][0];
		ll d = dp[down][1];
		dp[up][0] = max(t, d + len);
		dp[down][1] = max(d, t + len);
		ans = max(ans, max(dp[up][0], dp[down][1]));
	}

	printf("%lld", ans);
	return 0;
}