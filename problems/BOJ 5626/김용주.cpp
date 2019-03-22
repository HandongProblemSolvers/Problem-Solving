//BOJ5626 제단
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 10001
#define MOD 1000000007
typedef long long ll;

int N, arr[MAX_N], h;
ll dp[MAX_N], prv[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	if(arr[0] > 0 || arr[N-1] > 0){
		printf("0");
		return 0;
	}
	prv[0] = 1;
	//prv가 이전 열, dp가 현재 열.
    for (int i = 1; i < N; i++) {
		memset(dp, 0, sizeof(dp));
		if (arr[i] == -1) {
			for (int j = 0; j < (N + 1) / 2; j++) {
				if (j == 0) dp[j] = (prv[0] + prv[1]) % MOD;
				else dp[j] = (prv[j - 1] + prv[j] + prv[j + 1]) % MOD;
			}
		}

		else if (arr[i] == 0)
			dp[0] = (prv[0] + prv[1]) % MOD;

		else {
			h = arr[i];
			dp[h] = (prv[h - 1] + prv[h] + prv[h + 1]) % MOD;
		}
        //넘어가기 전에 바꿔주면서 prv가 update
		swap(prv, dp);
	}
    //prv[0] = dp[0] + dp[1]. 여기서 dp는 바로 앞열의 경우의 수가 저장되어 있음.
	printf("%lld", prv[0]);
	return 0;
}
