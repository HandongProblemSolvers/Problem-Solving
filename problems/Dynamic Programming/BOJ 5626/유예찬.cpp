// baekjoon 5626 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define EXIT() { return !printf("0"); }
using namespace std;
typedef long long ll;
const int MAX_N=10001;
const ll DIV_NUM=1000000007;

int N, start, end, length=1, x;
ll dp[MAX_N], tmp[MAX_N], ret=1;

int main() {
	scanf("%d", &N);
	scanf("%d", &x);
	if (x != -1 && x != 0) EXIT();

	for (int i=1; i<N; i++) {
		if (ret == 0) EXIT();
		scanf("%d", &x);
		if (x==-1 && i != N-1) length++;
		else {
			if (x == -1) x=0;
			if (i == N-1 && x != 0) EXIT();
			memset(tmp, 0, sizeof(tmp));
			tmp[start]=1;
			for (int j=1; j<=length; j++) {
				for (int k=max(0,start-j); k < min(MAX_N, start+j+1); k++) {
					dp[k] = tmp[k];
					if (k-1 >= 0) dp[k] += tmp[k-1];
					if (k+1 < MAX_N) dp[k] += tmp[k+1];
					dp[k] %= DIV_NUM;
				}
				for (int k=max(0,start-j); k<min(MAX_N, start+j+1); k++) tmp[k]=dp[k];
			}
			ret = (ret * dp[x]) % DIV_NUM;
			start = x, length = 1;
		}
	}
	printf("%lld\n", ret);

	return 0;
}