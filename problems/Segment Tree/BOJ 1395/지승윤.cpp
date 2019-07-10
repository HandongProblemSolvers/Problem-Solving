#include<cstdio>
#define MAXX 400040
using namespace std;
int tree[MAXX], lazy[MAXX];
int n, m, o, s, t;
void update_lazy(int node, int left, int right) {
	if (lazy[node]) {
		tree[node] = (right - left + 1) - tree[node];
		if (left != right) {
			lazy[node * 2] = !(lazy[node * 2]);
			lazy[node * 2 + 1] = !(lazy[node * 2 + 1]);
		}
		lazy[node] = 0;
	}
}
void update(int lo, int hi, int node, int left, int right) {
	update_lazy(node, left, right);
	if (hi < left || right < lo) return;
	if (lo <= left &&right <= hi) {
		tree[node] = (right - left + 1) - tree[node];
		if (left != right) {
			lazy[node * 2] = !(lazy[node * 2]);
			lazy[node * 2 + 1] = !(lazy[node * 2 + 1]);
		}
		return;
	}
	int mid = (left + right) >> 1;
	update(lo, hi, node * 2, left, mid);
	update(lo, hi, node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int sum(int lo, int hi, int node, int left, int right) {
	update_lazy(node, left, right);
	if (hi < left || right < lo) return 0;
	if (lo <= left && right <= hi) return tree[node];
	int mid = (left + right) >> 1;
	int lcv = sum(lo, hi, node * 2, left, mid);
	int rcv = sum(lo, hi, node * 2 + 1, mid + 1, right);
	return lcv + rcv;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &o, &s, &t);
		if (o)
			printf("%d\n", sum(s - 1, t - 1, 1, 0, n - 1));
		else
			update(s - 1, t - 1, 1, 0, n - 1);
	}
	return 0;
}
