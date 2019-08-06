#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 18; // Roundup of log2(100000) + 1
const int SIZE = 100001;
int N,M,u,v;
int parent[SIZE][MAX],depth[SIZE];
vector<int> adj[SIZE];

void makeTree(int node)
{
  for(int next : adj[node]){
    if(depth[next] == -1){
      depth[next] = depth[node] + 1;
      parent[next][0] = node;
      makeTree(next);
    }
  }
}

int main(void)
{
  scanf("%d",&N);
  for(int i=0; i<N-1; i++){
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(parent,-1,sizeof(parent));
  memset(depth,-1,sizeof(depth));
  depth[1] = 0;
  makeTree(1);

  for(int j=0; j<MAX; j++){
    for(int i=2; i<=N; i++){
      if(parent[i][j] == -1) continue;
      parent[i][j+1] = parent[parent[i][j]][j];
    }
  }

  scanf("%d",&M);
  while(M--){
    scanf("%d%d",&u,&v);

    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];

    for(int i=0; diff; i++){
      if(diff%2) u = parent[u][i];
      diff /= 2;
    }

    if(u != v){
      for(int i=MAX-1; i>=0; i--){
        if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]){
          u = parent[u][i];
          v = parent[v][i];
        }
      }
      u = parent[u][0];
    }

    printf("%d\n",u);
  }
  return 0;
}