#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long n, arr[10010], dp[2][10010];

int main() {
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);

        // 예외케이스
    dp[0][0] = arr[1] < 1 ? 1 : 0;

    for(int i = 2; i <= n; i++) {
        fill_n(&dp[1][0], MAX, 0);
        // dp[0]은 이전 탑의 경우의 수, dp[1]은 현재 탑의 경우의 수

        if(arr[i] == -1) {
            dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
            for(int k = 1; k <= MAX / 2; k++)
                dp[1][k] = (dp[0][k-1] + dp[0][k] + dp[0][k+1]) % MOD;
        }

        else if(arr[i] == 0)
            dp[1][arr[i]] = (dp[0][arr[i]] + dp[0][arr[i]+1]) % MOD;

        else
            dp[1][arr[i]] = (dp[0][arr[i]-1] + dp[0][arr[i]] + dp[0][arr[i]+1]) % MOD;

        swap(dp[0], dp[1]);
    }
    printf("%lld\n", dp[0][0]);
    return 0;
}
