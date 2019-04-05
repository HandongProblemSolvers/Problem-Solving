#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

typedef vector<long long> vll;
typedef long long ll;
const ll INF = 9876543211;
vll seg;
vll arr;

ll mn2(ll a, ll b) {
	return (a > b) ? b : a;
}

ll init(int node, int start, int end) {
	if (start == end) {
		return seg[node] = arr[start];
	}
	return seg[node] = mn2(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}

ll query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return seg[node];

	return mn2(query(2 * node, start, (start + end) / 2, left, right),
		query(2 * node + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);

	// tree create
	int h = ceil(log2(n));
	//printf("%d", h);
	seg = vll(1 << (h + 2), 0);
	arr = vll(n, 0);

	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

	init(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		ll res = query(1, 0, n - 1, a - 1, b - 1);
		printf("%lld\n", res);
	}

	return 0;
}


출처: https://wondy1128.tistory.com/151 [원도블로그]