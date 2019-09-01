//BOJ2300 기지국
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 10001
typedef pair<int, int> P;

int N, dp[MAX_N];
vector<P> cod;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cod.push_back({x, abs(y)});
    }
    sort(cod.begin(), cod.end());

    dp[0] = cod[0].second * 2;
    for(int i = 1; i < N; i++){
        int h = cod[i].second * 2;
        dp[i] = dp[i-1] + h;
        for(int j = i-1; j > 0; j--){
            h = max(h, cod[j].second * 2);
            dp[i] = min(dp[i], max(h, cod[i].first - cod[j].first) + dp[j-1]);
        }
        dp[i] = min(dp[i], max(h, cod[i].first - cod[0].first));
    }

    printf("%d\n", dp[N-1]);
    return 0;
}