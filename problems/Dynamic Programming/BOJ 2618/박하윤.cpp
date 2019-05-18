// 2618_DP_경찰차
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][1001], n, w, back[1001];
pair<int, int> d[1001];
int getdist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second); // 거리 차를 구하는 함수
}

int func(int x, int y) {  // 총 거리의 합 (min으로)
    if (x == w || y == w) return 0;
    int &ret = dp[x][y];
    if (ret != -1)return ret;
    int fir, sec;
    if (!x) //x 가 0일때 => 처음 위치가 1,1
        fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], { 1,1 });
    else  // 그 외에
        fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
    if (!y) //y가 0일때 => 처음 위치가 n,n
        sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], { n,n });
    else // 그 외
        sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);
    return ret = min(fir, sec);
}

void solve(int x, int y) {
    if (x == w || y == w) return;
    int fir, sec;
    if (!x)
        fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], { 1,1 });
    else
        fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
    if (!y)
        sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], { n,n });
    else
        sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);

    if (fir < sec) { // 1번 경찰차가 더 가까운 거리일 경우
        back[max(x, y) + 1] = 1;
        solve(max(x, y) + 1, y);
    }
    else {
        back[max(x, y) + 1] = 2;
        solve(x, max(x, y) + 1);
    }
}

int main() {
    memset(dp, -1, sizeof(dp)); // dp 초기화
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= w; i++)  // 사건이 일어난 위치 입력
        scanf("%d%d", &d[i].first, &d[i].second);

    printf("%d\n", func(0, 0));
    solve(0, 0);
    for (int i = 1; i <= w; i++)
        printf("%d\n", back[i]);

    return 0;
}
