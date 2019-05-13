// baekjoon 2550 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N, top[MAX_N], bottom[MAX_N], idx[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &top[i]);
		idx[top[i]]=i;
	}

	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		bottom[i]=idx[x];
	}

	vector<int> lis(N+1, MAX_N);
	vector<pair<int,int>> trace;
	for (int i=0; i<N; i++) {
		int index = lower_bound(lis.begin(),lis.end(), bottom[i]) - lis.begin();
		lis[index] = bottom[i];
		trace.push_back({index, bottom[i]});
	}

	int cnt=0;
	for (int i=0; i<N; i++) {
		if (lis[i] == MAX_N) break;
		cnt++;
	}
	printf("%d\n", cnt);

	cnt--;
	int tlen = trace.size();
	vector<int> ansIdx;
	for (int i=tlen; i>=0; i--) {
		if (trace[i].first != cnt) continue;
		ansIdx.push_back(trace[i].second);
		cnt--;
	}

	vector<int> ans;
	for (int i=0; i<ansIdx.size(); i++)
		ans.push_back(top[ansIdx[i]]);

	sort(ans.begin(), ans.end());

	for (int i=0; i<ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size()) printf(" ");
		else printf("\n");
	}

	return 0;
}