#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=61;
typedef long long ll;
int N;
ll x, y;

void Mos(int n, ll left, ll right, ll nodeX, ll nodeY, int carry) {
	if (right < nodeX || nodeY < left) return;
	if (n == 1) {
		putchar(carry+'0');
		return;
	}
	ll mid = (left + right)/2;
	Mos(n-1, left, mid, nodeX, nodeY, carry);
	Mos(n-1, mid+1, right, nodeX, nodeY, (carry+1)%2);
}

int main(void) {
	scanf("%d%lld%lld", &N, &x, &y);
	Mos(N, 1, (1LL<<(N-1)), x, y, 0);
    return 0;
}