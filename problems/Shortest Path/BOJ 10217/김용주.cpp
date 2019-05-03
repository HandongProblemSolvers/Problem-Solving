//BOJ10217 KCM Travel
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 101
#define MAX_M 10001
const int INF = 1e9;
typedef pair<int, int> P;

int T, n, m, k, ans, visit[MAX_N][MAX_M];
vector<pair<int, P>> adj[MAX_N];

int dfs(int cur, int cost){
    if(cost > m) return INF;
    if(visit[cur][cost]) return visit[cur][cost];
    if(cur == n) return 0;

    int result = INF;
    for(int i = 0; i < adj[cur].size(); i++){
        int v = adj[cur][i].first;
        int c = adj[cur][i].second.first;
        int d = adj[cur][i].second.second;
        result = min(result, d + dfs(v, cost + c));
    }
    return visit[cur][cost] = result;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < k; i++){
            int a1, a2, a3, a4;
            scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
            adj[a1].push_back({a2, {a3, a4}});
        }
        ans = dfs(1, 0);
        memset(visit, 0, sizeof(visit));
        if(ans >= INF) printf("Poor KCM\n");
        else printf("%d\n", ans);
        for(int i = 0; i < n; i++) adj[i].clear();
    }
    return 0;
}