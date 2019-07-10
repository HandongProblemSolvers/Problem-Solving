#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_SIZE=1<<18;

int N, M, seg[ST_SIZE];
bool lazy[ST_SIZE];

struct SegTree {
	int start, seg[ST_SIZE];
	bool lazy[ST_SIZE];

	SegTree() {
		start = ST_SIZE/2;
		fill(seg, seg+ST_SIZE, 0);
		fill(lazy, lazy+ST_SIZE, false);
	}

	// propagate in [ns, ne]
	void propagate(int node, int ns, int ne) {
		if (lazy[node]) {
			lazy[node] = false;
			if (node < start) {
				lazy[node*2] ^= 1;
				lazy[node*2+1] ^= 1;
				seg[node] = 0;
				if (lazy[node*2]) seg[node] += (ne-ns+1)/2 - seg[node*2];
				else seg[node] += seg[node*2];
				if (lazy[node*2+1]) seg[node] += (ne-ns+1)/2 - seg[node*2+1];
				else seg[node] += seg[node*2+1];
			}
			else seg[node] ^= 1;
		}
	}

	// reverse [ns, ne]
	void update(int s, int e) { update(s, e, 1, 0, start-1); }
	void update(int s, int e, int node, int ns, int ne) {
		propagate(node, ns, ne);

		if (e < ns || ne < s) return;
		if (s <= ns && ne <= e) {
			lazy[node] ^= 1;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne)/2;
		update(s, e, node*2, ns, mid);
		update(s, e, node*2+1, mid+1, ne);
		seg[node] = seg[node*2] + seg[node*2+1];
	}

	// sum [ns, ne]
	int sum(int s, int e) { return sum(s, e, 1, 0, start-1); }
	int sum(int s, int e, int node, int ns, int ne) {
		propagate(node, ns, ne);
		if (e < ns || ne < s) return 0;
		if (s <= ns && ne <= e) return seg[node];
		int mid = (ns + ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid+1, ne);
	}
};

int main() {
	scanf("%d%d", &N, &M);
	SegTree seg;
	for (int i=0; i<M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) seg.update(b, c);
		else printf("%d\n", seg.sum(b, c));
	}
	return 0;
}