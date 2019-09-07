//BOJ2281 데스노트
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_M 1001
const int INF = 2e9;

int n, m, name[MAX_M], dp[MAX_M][MAX_M];

int tdp(int col, int cur){
    if(cur == n) return 0;
    if(col == m) return tdp(name[cur]+1, cur+1) + 1;
    if(col > m) return tdp(name[cur]+1, cur+1);
    int &ret = dp[col][cur];
    if(ret != -1) return ret;

    ret = tdp(name[cur]+1, cur+1) + (m - col + 1) * (m - col + 1);
    if(col + name[cur] <= m) ret = min(ret, tdp(col + name[cur]+1, cur+1));

    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &name[i]);

    memset(dp, -1, sizeof(dp));
    printf("%d", tdp(name[0]+1, 1));
    return 0;
}