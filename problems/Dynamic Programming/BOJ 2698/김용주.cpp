//BOJ2698 인접한 비트의 개수
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 101
typedef long long ll;

int T, n, k;
ll dp[MAX_N][MAX_N][2];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &k);
		memset(dp, 0, sizeof(dp));
		dp[1][0][0] = 1;
		dp[1][0][1] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 0; j <= k; j++){
				dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
				dp[i][j][1] += dp[i-1][j][0];
				if(j > 0) dp[i][j][1] += dp[i-1][j-1][1];
	 		}
		}
		printf("%lld\n", dp[n][k][0] + dp[n][k][1]);
	}

	return 0;
}