//BOJ11526 백양로 브레이크
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 251
const int INF = 1e9;
int n, m, u, v, b, k, s, e, road[MAX_N][MAX_N];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            road[i][j] = (i == j) ? 0 : INF;

    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &b);
        road[u][v] = 0;
        road[v][u] = (b) ? 0 : 1;
    }

    for(int h = 1; h <= n; h++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                road[i][j] = min(road[i][j], road[i][h] + road[h][j]);

    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", road[s][e]);
    }

    return 0;
}