// baekjoon 1781 yechan
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=200001;

int N;
P cups[MAX_N];
priority_queue<int> PQ;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		cups[i].first = x;
		cups[i].second = y;
	}
	sort(cups, cups+N, greater<P>());

	int pos = 0;
	int t = cups[0].first;
	int ret = 0;
	while (t) {
		while (pos < N && t == cups[pos].first) {
			PQ.push(cups[pos].second);
			pos++;
		}
		if (!PQ.empty()) {
			ret += PQ.top();
			PQ.pop();
		}
		t--;
	}
	printf("%d\n", ret);
	return 0;
}