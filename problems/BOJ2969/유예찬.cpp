// baekjoon 2969 yechan
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
const int MAX_N=1501;
const int MIN_INF=-1e9;

struct Flower{
	int r, c;
	int petal;
	Flower():r(-1),c(-1),petal(0){}
	Flower(int r, int c, int petal):r(r),c(c),petal(petal){}
};

bool cmp(const Flower& a, const Flower& b) {
	return a.petal < b.petal;
}

struct PosAndDP{
	int x, value;
	PosAndDP():x(MIN_INF),value(MIN_INF){}
	PosAndDP(int x, int value):x(x),value(value){}
};

struct Pos2dAndDP{
	int r, c, value;
	Pos2dAndDP():r(-1),c(-1),value(MIN_INF){}
	Pos2dAndDP(int r, int c, int value):r(r),c(c),value(value){}
};

struct MemoPosAndDP{
	PosAndDP data[4];
	void update(int x, int value) {
		int i = 0;
		PosAndDP input = PosAndDP(x, value);
		for (i=0; i<4; i++) {
			if (data[i].value < input.value) {
				break;
			}
		}
		if (i == 4) return;
		PosAndDP target, tmp;
		target = input;
		while (i < 4) {
			tmp = data[i];
			data[i] = target;
			target = tmp;
			i++;
		}
	}
	int findMaximum(int x) {
		for (int i=0; i<4; i++) {
			if (abs(data[i].x - x) > 1) {
				return data[i].value;
			}
		}
		return 0;
	}
};

int N, R, C, board[MAX_N][MAX_N], ans;
Flower flowers[MAX_N*MAX_N];
MemoPosAndDP rows[MAX_N], cols[MAX_N];

int main() {
	scanf("%d", &N);
	scanf("%d%d", &R, &C);
	R--, C--;
	for (int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
			flowers[i*N+j]= Flower(i, j, board[i][j]);
		}
	}
	sort(flowers, flowers+N*N, cmp);

	queue<Pos2dAndDP> q;
	int prev_v;
	ans = 1;
	int ret = 1;
	int start = 0;
	for (int i=0; i<N*N; i++) {
		if (flowers[i].r == R && flowers[i].c == C) {
			rows[R].update(C, 1);
			cols[C].update(R, 1);
			prev_v=flowers[i].petal;
			while ((i < N*N) && (prev_v == flowers[i].petal)) {
				i++;
			}
			start = i;
			break;
		}
	}
	for (int i=start; i<N*N; i++) {
		if (prev_v != flowers[i].petal) {
			while (!q.empty()) {
				Pos2dAndDP tmp = q.front();
				rows[tmp.r].update(tmp.c, tmp.value);
				cols[tmp.c].update(tmp.r, tmp.value);
				q.pop();
			}
			prev_v = flowers[i].petal;
		}
		ret = MIN_INF;
		if (flowers[i].r - 1 >= 0)
			ret = max(ret, rows[flowers[i].r - 1].findMaximum(flowers[i].c) + 1);
		if (flowers[i].r + 1 < N)
			ret = max(ret, rows[flowers[i].r + 1].findMaximum(flowers[i].c) + 1);
		if (flowers[i].c - 1 >= 0)
			ret = max(ret, cols[flowers[i].c - 1].findMaximum(flowers[i].r) + 1);
		if (flowers[i].c + 1 >= 0)
			ret = max(ret, cols[flowers[i].c + 1].findMaximum(flowers[i].r) + 1);
		ans = max(ans, ret);
		q.push(Pos2dAndDP(flowers[i].r, flowers[i].c, ret));
	}
	printf("%d\n", ans);
	return 0;
}