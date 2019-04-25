// baekjoon 13251 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=51;

int M, K, N, color[MAX_N];
double ans;

int main() {
	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		scanf("%d", &color[i]);
		N += color[i];
	}
	scanf("%d", &K);
	for (int i=0; i<M; i++) {
		double tmp = 1;
		for (int j=0; j<K; j++)
			tmp *= (double)(color[i]-j)/(N-j);
		ans += tmp;
	}
	printf("%.20f\n", ans);
	return 0;
}