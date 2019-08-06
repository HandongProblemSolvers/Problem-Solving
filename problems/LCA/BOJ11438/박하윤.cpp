// LCA_LCA2_11438

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int max_N = 100001;
const int max_k = 18;

int N, M;
vector<int> adj[max_N];
int parent[max_N][max_k];
int depth[max_N];

// 깊이와 부모값을 넣어주면서 트리 만들기
void makeTreeDfs(int cur){
  for(int next : adj[cur]){
    if(depth[next] == -1){
      parent[next][0] = cur;
      depth[next] = cur+1;
      makeTreeDfs(next);
    }
  }
}

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // 초기화
  memset(parent, -1, sizeof(parent));
  fill(depth, depth+N, -1);
  depth[0] = 0;
  makeTreeDfs(0);

  // 각 노드마다 2^k번째 부모 값들 넣어주기
  for(int i = 0; i < max_k-1; i++){
    for(int j = 1; j < N; j++){
      if(parent[j][i] != -1)
        parent[j][i+1] = parent[parent[j][i]][i];
    }
  }
  scanf("%d", &M);
  while(M--){
    int u, v;
    u--; v--;
    // 둘의 깊이 차 없애기
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < diff; i++){
      if(diff % 2 != 0) u = parent[u][i];
      diff = diff/2;
    }

    if(u != v){
      for(int i = max_k-1; i >= 0; i--){
        if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
          u = parent[u][i];
          v = parent[v][i];
        }
      }
      u = parent[u][0];
    }
    printf("%d\n", u+1);
  }
  return 0;
}
