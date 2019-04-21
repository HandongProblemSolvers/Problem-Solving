#include <cstdio>
#include <algorithm>
using namespace std;

int W[11][11];
int N;

int TSP(int v, int visit, int cost, int begin)
{
    int ret = 2e9;
    visit |= (1<<v-1);
    if(visit==((1<<N)-1)) return W[v][begin] ? cost+W[v][begin] : ret;

    for(int i=1; i<=N; i++){
        if(i==v) continue;
        if(!W[v][i]) continue;
        if(visit & (1<<i-1)) continue;
        ret = min(ret, TSP(i,visit,cost+W[v][i],begin));
    }
    return ret;
}

int main(void)
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&W[i][j]);
        }
    }
    int ans = 2e9;
    for(int i=1; i<=N; i++) ans = min(ans,TSP(i,0,0,i));
    printf("%d",ans);
    return 0;
}