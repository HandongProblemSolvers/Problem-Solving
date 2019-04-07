//BOJ10868 최솟값
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
const int SIZE = 1 << 17;
int arr[2 * SIZE], N, M, ans;

//Segment tree update(만들기)
void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
	}
}

//세그먼트트리를 이용해 구간의 최솟값 찾기.
int findMin(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (R < nodeL || nodeR < L) return INF;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(findMin(nodeL, mid, nodeNum * 2, L, R), findMin(mid + 1, nodeR, nodeNum * 2 + 1, L, R));
}

int main() {
	scanf("%d %d", &N, &M);
	fill(arr, arr + SIZE * 2, INF);
	for (int i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		update(i, a);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ans = findMin(0, SIZE - 1, 1, a, b);
		printf("%d\n", ans);
	}
	return 0;
}