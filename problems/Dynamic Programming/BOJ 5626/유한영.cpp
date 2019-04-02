#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define mod 1000000007 // 나눠주는 값을 define

int main() {
	int N, t=1;
	int set[10010];
	long long dp[2][10010]; // dp에 들어갈 값이 굉장히 커지므로 배열의 자료형을 longlong으로
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> set[i];
		if (set[i] != -1)set[i]++;
	}
	dp[0][1] = (set[0] == -1 || set[0] == 1) ? 1 : 0;
	for (int i = 1; i < N; i++, t = 1 - t) { // t = 1-t 로 t가 1과 0으로 왔다 갔다 
		memset(dp[t], 0, sizeof(dp[t])); // 함수의 특정 부분을 어떤 값으로 지정할 때 사용 
		if (set[i] == -1) {
			for (int j = 1; j <= N; j++) {
				dp[t][j] = (dp[1 - t][j - 1] + dp[1 - t][j] + dp[1 - t][j + 1]) % mod;
			}
		}
		else {
			dp[t][set[i]] = (dp[1 - t][set[i] - 1] + dp[1 - t][set[i]] + dp[1 - t][set[i] + 1]) % mod;
		}
	}

	cout<<dp[1 - t][1];
}
