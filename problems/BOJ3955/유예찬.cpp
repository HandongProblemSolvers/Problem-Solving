// baekjoon 3955 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

// KX + 1 = CY
// x < 0, y > 0 이라고 하자
// Kx + Cy = 1 >> Euclid 형태 >> gcd가 1인
// 해=(x0, y0)라고 하자
// Kx + Cy = K(x0+tC) + C(y0-tK) = 1
// 일반해 = (x0+tC, y0-tK)
// x0 + tC < 0, 0 < y0 - tK <= 10^9
// t < - x0/C  and  t < y0/K  and  (y0-10^9)/K <= t
// (y0 - 10^9)/K <= t < min(-x0/C, y0/K)

struct Euclid{
	ll x, y, d;
	Euclid():x(0),y(0),d(0){}
	Euclid(ll x, ll y, ll d):x(x),y(y),d(d){}
};

Euclid extEuclid(ll a, ll b) {
	if (b == 0) return Euclid(1, 0, a);
	Euclid ret = extEuclid(b, a%b);
	return Euclid(ret.y, ret.x - (a/b)*ret.y, ret.d);
}

// b > 0 (always)
ll ceil(ll a, ll b) {
	return (a >= 0) ? (a+b-1)/b : (a/b);
}

ll T, K, C, ans, t;

int main() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld", &K, &C);
		Euclid ret = extEuclid(K, C);
		if (ret.d != 1) puts("IMPOSSIBLE");
		else {
			t = min(ceil(-ret.x, C), ceil(ret.y, K)) - 1;
			ans = ret.y - K*t;
			if (ans > 1e9) puts("IMPOSSIBLE");
			else printf("%lld\n", ans);
		}
	}
	return 0;
}