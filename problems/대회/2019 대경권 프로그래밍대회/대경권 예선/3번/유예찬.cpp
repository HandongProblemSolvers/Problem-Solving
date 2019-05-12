#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int N, K;
int root[MAX_N];
bool visited[MAX_N];

int find(int x) {
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a==b) return;
	if (root[a] > root[b]) swap(a, b);
	root[a] += root[b];
	root[b] = a;
}

int main() {
	memset(root, -1, sizeof(root));
	scanf("%d%d", &N, &K);
	for (int i=0; i<K; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		merge(u,v);
	}

	long long ret = (N*(N-1))/2;
	for (int i=0; i<N; i++) {
		int rt = find(i);
		if (!visited[rt]) {
			visited[rt]=true;
			ret -= (root[rt]*(root[rt]+1))/2;
		}
	}
	printf("%lld\n", ret);
	return 0;
}