// baekjoon 10868 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE=1<<17;

int N, M, x, a, b;
int arr[SIZE*2];

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = min(arr[i*2], arr[i*2+1]);
	}
}

int segMin(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (R < nodeL || nodeR < L) return 1e9;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(segMin(nodeL, mid, nodeNum*2, L, R), segMin(mid+1, nodeR, nodeNum*2+1, L, R));
}

int segMin(int L, int R) {
	return segMin(0, SIZE-1, 1, L, R);
}

int main() {
	fill(arr, arr+SIZE*2, 1e9);
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%d", &x);
		update(i, x);
	}
	while (M--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", segMin(a,b));
	}
	return 0;
}