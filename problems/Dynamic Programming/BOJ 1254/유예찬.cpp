// baekjoon 1254 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 2001;

int dp[MAX_N][MAX_N];
char str[MAX_N];

int main() {
	scanf("%s", str+1);
	int slen=strlen(str+1);
	int maxlen=1;
	for (int i=1; i<=slen; i++) {
		for (int j=1; j<=slen; j++) {
			if (str[j] == str[slen-i+1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			if (j == slen && dp[i][j] == i) maxlen=max(maxlen, i);
		}
	}
	printf("%d\n", slen+slen-maxlen);
	return 0;
}
