// baekjoon 10806 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N=100001;

int N, M, C1, C2, root[MAX_N], disc[MAX_N];
vector<int> adj[MAX_N];
vector<pair<int, int> > connect;
vector<int> node[MAX_N];

int find(int x) {
    if (!root[x]) return x;
    return root[x]=find(root[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a,b);
    root[b]=a;
}

void dfs(int here, int parent, int distance) {
    disc[here] = distance;
    int parent_conut=0;
    for (int i=0; i<adj[here].size(); i++) {
        int there = adj[here][i];
        if (there == here) continue;
        if (there == parent && !parent_conut) {
            parent_conut++;
            continue;
        }
        if (!disc[there]) {
            dfs(there, here, distance+1);
            if (disc[there] == distance+1) connect.push_back({here, there});
            else merge(here, there);
        }
        disc[here] = min(disc[here], disc[there]);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d%d", &C1, &C2);
        adj[C1].push_back(C2);
        adj[C2].push_back(C1);
    }
    dfs(1, -1, 1);
    for (int i=0; i<connect.size(); i++) {
        int a = find(connect[i].first);
        int b = find(connect[i].second);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int singleNodeCnt = 0;
    vector<int> v;
    for (int i=1; i<=N; i++){
        if (node[i].size() == 1) {
            singleNodeCnt++;
            v.push_back(i);
        }
    }
    printf("%d\n", (singleNodeCnt+1)/2);

    for (int i=1; i<v.size(); i+=2)
        printf("%d %d\n", v[i-1], v[i]);

    if (v.size() % 2)
        printf("%d %d\n", v[v.size()-2], v[v.size()-1]);
    return 0;
}