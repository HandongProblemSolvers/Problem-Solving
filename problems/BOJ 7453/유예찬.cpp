// baekjoon 7453 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, i, j, z, NN;
ll ret, d[4][4000], tw0[16000001], tw1[16000001];

int main() {
	scanf("%d", &N);
	NN = N*N;
	for (j=0; j<N; j++)
		for (i=0; i<4; i++)
			scanf("%lld", &d[i][j]);

	for (int i=0, z=0; i<N; i++)
		for (int j=0; j<N; j++, z++)
			tw0[z] = d[0][i] + d[1][j],\
			tw1[z] = d[2][i] + d[3][j];

	sort(tw0, tw0+NN);
	sort(tw1, tw1+NN);

	for (i=0; i<NN; i++)
		ret += upper_bound(tw1, tw1+NN, -tw0[i]) - \
		 	   lower_bound(tw1, tw1+NN, -tw0[i]);
	printf("%lld\n", ret);
	return 0;
}