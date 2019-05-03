#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
#define mp(u,v) make_pair((u),(v))
#define mmp(u,v,s) mp((u),mp(v,s))
#define pb(u) push_back((u))
#define third second.second
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
 
typedef vector<int> vint;
const int maxv = 101;
const int INF = 1234567890;
int V, E, st, en, M;
 
vector<piii> adj[maxv];
vector<vint> dist;
 
 
void dijk(){
    dist = vector<vint>(V,vint(M+1, INF));
    dist[0][0] = 0;   
  //vertex cost = time
    queue<piii> pq;
    pq.push(mmp(0, 0, 0));
 
    while (!pq.empty()){
        int u = pq.front().first;
        int cost = pq.front().second.first;
        int time = pq.front().third;
        pq.pop();
 
        if (time > dist[u][cost]) continue;
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int nCost = adj[u][i].second.first;
            int nTime = adj[u][i].third;
            if (nCost + cost > M)continue;
            if (nTime + dist[u][cost] < dist[v][nCost + cost]){
                dist[v][nCost + cost] = nTime + dist[u][cost];
                pq.push(mmp(v, nCost + cost, nTime + time));
            }
        }
    }
}
int main(){
    int t1, t2, t3, t4;
    int t;  cin >> t;
    while (t--){
        cin >> V >> M >> E;
        for (int i = 0; i < E; i++){
            scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
            adj[t1 - 1].push_back(mmp(t2 - 1, t3, t4));
        }
 
        dijk();
        int ret = INF;
        for (int i = 0; i <= M; i++)
            if (dist[V - 1][i] != INF)
                ret = min(ret, dist[V - 1][i]);
        if (ret!= INF)
            cout << ret << endl;
        else
            cout << "Poor KCM" << endl;
        for (int i = 0; i < V; i++)
            adj[i].clear();
    }
}
