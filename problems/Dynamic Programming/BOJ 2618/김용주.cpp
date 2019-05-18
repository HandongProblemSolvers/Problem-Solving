//BOJ2618 경찰차
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_W 1002
const int INF = 1e9;
typedef long long ll;
typedef pair<int, int> P;
int n, w, dp[MAX_W][MAX_W];
P d[MAX_W];

int dist(P a, P b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int tdp(int a, int b){
    if(a == w || b == w) return 0;
    if(dp[a][b] != 0) return dp[a][b];
    //몇번째 사건인지 기록
    int next = max(a, b) + 1;
    int first = tdp(next, b) + dist(d[next], d[a]);
    //b의 위치는 n,n에서 시작
    int second;
    if(b == 0) second = tdp(a, next) + dist(d[next], d[w+1]);
    else second = tdp(a, next) + dist(d[next], d[b]);
    int result = min(first, second);
    return dp[a][b] = result;
}

void tracking(int a, int b){
    if(a == w || b == w) return;
    int next = max(a, b) + 1;
    int first = dp[next][b] + dist(d[next], d[a]);
    int second; 
    if(b == 0) second = dp[a][next] + dist(d[next], d[w+1]);
    else second = dp[a][next] + dist(d[next], d[b]);

    if(first < second){
        printf("1\n");
        tracking(next, b);
    }
    else{
        printf("2\n");
        tracking(a, next);
    }
    return;
}

int main(){
    scanf("%d %d", &n, &w);
    for(int i = 1; i <= w; i++){
        scanf("%d %d", &d[i].first, &d[i].second);
    }
    d[0] = make_pair(1, 1);
    d[w+1] = make_pair(n, n);
    int ans = tdp(0, 0);
    printf("%d\n", ans);
    tracking(0, 0);

    return 0;
}