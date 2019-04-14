// baekjoon 1701 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=5001;

int pi[MAX_N], slen, ans;
char S[MAX_N];

int main() {
	scanf("%s", S);
	slen = strlen(S);

	for (int k=0; k<slen; k++) {
		memset(pi, 0, sizeof(pi));
		for (int i=1+k, j=0; i<slen; i++) {
			while (j && S[i] != S[j+k]) j = pi[j+k-1];
			if (S[i] == S[j+k]) pi[i] = ++j;
			ans = max(ans, j);
		}
	}
	printf("%d\n", ans);

	return 0;
}