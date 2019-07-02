// baekjoon 2342 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
const int MAX_INF=2e9;
const int mat[5][5] = { {0,2,2,2,2}, {0,1,3,4,3}, {0,3,1,3,4}, {0,4,3,1,3}, {0,3,4,3,1} };

int N, x;
int data[MAX_N]; // game step
int dp[5][5][MAX_N]; // (left, right, pos)

int dfs(int left, int right, int pos) {
	if (pos == N) return 0;
	int &ret = dp[left][right][pos];
	if (ret) return ret;

	if (left == data[pos] || right == data[pos]) return ret = dfs(left, right, pos+1) + 1;

	ret = MAX_INF;
	// move left
	ret = min(ret, dfs(data[pos], right, pos+1)+mat[left][data[pos]]);
	// move right
	ret = min(ret, dfs(left, data[pos], pos+1)+mat[right][data[pos]]);
	return ret;
}

int main() {
	while (1) {
		scanf("%d", &x);
		if (!x) break;
		data[N++] = x;
	}

	printf("%d\n", dfs(0, 0, 0));
	return 0;
}