//BOJ2342 DDR
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 100001
const int INF = 1e9;

int N, dp[5][5][MAX_N];
vector<int> step;

int value(int pos, int val){
    if(pos == 0) return 2;
    int next = abs(pos - val);
    if(!next) return 1;
    if(next == 2) return 4;
    return 3;
}

int ddr(int left, int right, int n){
    if(n == step.size()) return 0;
    if(dp[left][right][n] != -1) return dp[left][right][n];

    int l = value(left, step[n]);
    int r = value(right, step[n]);
    dp[left][right][n] = min(ddr(step[n], right, n + 1) + l, ddr(left, step[n], n + 1) + r);

    return dp[left][right][n];
}

int main(){
    while(1){
        int a;
        scanf("%d", &a);
        if(!a) break;
        step.push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", ddr(0, 0, 0));

    return 0;
}