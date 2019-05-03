#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct port{
    int src;
    int cost;
    int time;

    bool operator<(const port& rhs) const{
        if(time==rhs.time) return cost>rhs.cost;
        return time>rhs.time;
    }
};
vector<port> g[101];
int st[101][10001];
int tc,n,m,k,u,v,c,d;
const int INF = 2e9;
priority_queue<port> pq;

int dijk(port v)
{
    pq.push(v);
    st[v.src][0] = 0;
    int ans = INF;
    while(!pq.empty()){
        port p = pq.top(); pq.pop();
        if(st[p.src][p.cost] < p.time) continue;
        if(p.src==n) {
            ans = p.time;
            while(!pq.empty()) pq.pop();
            break;
        }
        st[p.src][p.cost] = p.time;
        for(port np : g[p.src]) {
            if(p.cost+np.cost>m) continue;
            if(p.time+np.time < st[np.src][p.cost+np.cost]){
                st[np.src][p.cost+np.cost] = p.time+np.time;
                pq.push({np.src,p.cost+np.cost,p.time+np.time});
            }
        }
    }
    return ans;
}

int main(void)
{
    scanf("%d",&tc);

    while(tc--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<k; i++){
            scanf("%d%d%d%d",&u,&v,&c,&d);
            g[u].push_back({v,c,d});
        }
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=m; j++){
                st[i][j] = INF;
            }
        }
        int ans = dijk({1,0,0});
        for(int i=1; i<=n; i++) g[i].clear();
        ans!=INF?printf("%d\n",ans):printf("Poor KCM\n");
    }

    return 0;
}