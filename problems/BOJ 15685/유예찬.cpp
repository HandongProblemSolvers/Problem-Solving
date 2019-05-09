// baekjoon 15685 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
const int SIZE=1<<12;
const int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int N, arr[SIZE], x, y, d, g;
bool visited[MAX_N][MAX_N];

int getCntRect() {
	int ret = 0;
	for (int i=0; i<MAX_N-1; i++)
		for (int j=0; j<MAX_N-1; j++)
			if (visited[i][j] && visited[i+1][j] && visited[i][j+1] && visited[i+1][j+1])
				ret++;
	return ret;
}

void draw(int x, int y, int g) {
	int idx = 0;
	int maxIdx = 1<<g;
	visited[x][y] = true;

	while (idx < maxIdx) {
		x = x + dir[arr[idx]][0];
		y = y + dir[arr[idx]][1];
		if (0 <= x && x < MAX_N && 0 <= y && y < MAX_N) visited[x][y] = true;
		idx++;
	}
}

void genArr(int cnt, int maxCnt) {
	if (cnt > maxCnt) return;

	for (int i=(1<<cnt)-1, j=0; i>=(1<<(cnt-1)); i--, j++) {
		arr[i] = (arr[j]+1)%4;
	}
	genArr(cnt+1, maxCnt);
}

int main() {
	scanf("%d",&N);
	for (int i=0; i<N; i++) {
		scanf("%d%d%d%d", &x, &y, &d, &g);
		arr[0]=d;
		genArr(1,g);
		draw(x, y, g);
	}
	printf("%d\n", getCntRect());
	return 0;
}