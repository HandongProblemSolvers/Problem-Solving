// baekjoon 9359 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll A, B, N;
int T;
vector<int> primes;

void getPrimes(ll x) {
	for (ll i=2; i*i <= x; i++) {
		if (x % i == 0) {
			primes.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1) primes.push_back(x);
}

inline ll getBetweenNum(ll num) {
	return (B/num - (A-1)/num);
}

ll dfs(int here, ll pos, ll sum) {
	if (here == primes.size()) return 0;
	ll ret = 0;
	ret += pos*getBetweenNum(sum*primes[here]);
	ret += dfs(here+1, pos, sum);
	ret += dfs(here+1, pos*(-1), sum*primes[here]);
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%lld%lld%lld", &A, &B, &N);
		primes.clear();
		getPrimes(N);
		printf("Case #%d: %lld\n", t, (B-A+1)-dfs(0, 1, 1));
	}
	return 0;
}