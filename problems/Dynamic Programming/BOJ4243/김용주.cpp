//BOJ4243 보안업체
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 101
typedef long long ll;
const ll INF = (1LL<<62);

ll dp[MAX_N][MAX_N][2], sum[MAX_N], ans;
int T, N, a;

ll visit(int left, int right, int state){
    ll &ret = dp[left][right][state];
    if(ret != -1) return ret;
    if(left <= 1 && right >= N) return 0;
    if(left > right) return INF;

    ret = INF;
    int rmd = N - right + left - 1;
    if(!state){
        if(left > 1) ret = min(ret, visit(left - 1, right, 0) + rmd * (sum[left] - sum[left-1]));
        if(right < N) ret = min(ret, visit(left, right + 1, 1) + rmd * (sum[right+1] - sum[left]));
    }

    else{
        if(left > 1) ret = min(ret, visit(left - 1, right, 0) + rmd * (sum[right] - sum[left-1]));
        if(right < N) ret = min(ret, visit(left, right + 1, 1) + rmd * (sum[right+1] - sum[right]));
    }

    return ret;
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(dp, -1, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        scanf("%d %d", &N, &a);
        for(int i = 2; i <= N; i++){
            ll b;
            scanf("%lld", &b);
            sum[i] = sum[i-1] + b;
        }        

        ans = min(visit(a, a, 0), visit(a, a, 1));
        printf("%lld\n", ans);
    }

    return 0;
}