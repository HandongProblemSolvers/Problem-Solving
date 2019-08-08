// baekjoon 1727 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N=1001;
const ll MAX_INF=0x3F3F3F3F3F3F3F3F;

int N, M;
int NList[MAX_N], MList[MAX_N];
int maxCount;
ll dp[MAX_N][MAX_N]; // state[remain person][position of N]

ll dfs(int count, int nc, int mc, int npass, int mpass)
{
	if (count == 0) return 0; // all matched
	if (nc == N || mc == M) return MAX_INF; // remain person, and the end
	int here = (N > M) ? nc : mc;
	ll &ret = dp[count][here];

	if (ret != MAX_INF) return ret;

	// match person
	ret = min(ret, dfs(count-1, nc+1, mc+1, npass, mpass)+abs(NList[nc] - MList[mc]));
	// nc pass
	if (N > M && npass+1 <= N-M) ret = min(ret, dfs(count, nc+1, mc, npass+1, mpass));
	// mc pass
	if (M > N && mpass+1 <= M-N) ret = min(ret, dfs(count, nc, mc+1, npass, mpass+1));
	return ret;
}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i=0; i<N; i++)
		scanf("%d", &NList[i]);
	sort(NList, NList+N);

	for (int i=0; i<M; i++)
		scanf("%d", &MList[i]);
	sort(MList, MList+M);

	memset(dp, 0x3f, sizeof(dp));
	printf("%lld\n", dfs(min(N,M), 0, 0, 0, 0));
	return 0;
}