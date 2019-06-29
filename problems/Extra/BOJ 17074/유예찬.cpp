// baekjoon 17074 yechan
#include <cstdio>
using namespace std;
const int MAX_N=200001;
const int MAX_INF=2e9;
const int MIN_INF=-2e9;
int N, cnt, cur, pprev, prev, pprev_v, prev_v, cur_v, next_v;

int main() {
	scanf("%d", &N);

	prev = pprev = MIN_INF;
	for (int i=0; i<N; i++) {
		scanf("%d", &cur);
		if (prev > cur) {
			if (cnt) return !printf("0\n");
			cnt++;
			pprev_v = pprev;
			prev_v = prev;
			cur_v = cur;
			next_v = MAX_INF;
		} else if (next_v == MAX_INF) {
			next_v = cur;
		}
		pprev = prev;
		prev = cur;
	}

	if (!cnt) return !printf("%d\n", N);
// pp p  c  n
// 1  3  1  3
	int result = 0;
// pop "prev_v"
	if (pprev_v <= cur_v) result++;
// pop "cur_v"
	if (prev_v <= next_v) result++;
	printf("%d\n", result);
	return 0;
}