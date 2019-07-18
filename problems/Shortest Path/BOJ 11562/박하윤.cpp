//Floyd_백양로 브레이크_11562
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int n, m, building[251][251], t;

int main(){
  scanf("%d %d", &n, &m);

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      building[i][j] = i==j ? 0 : INF;

  for(int i = 0; i < m; i++){
    int u, v, b;
    scanf("%d %d %d", &u, &v, &b);
    if(b == 0){
      building[u][v] = 0;
      building[v][u] = 1;
    } else {
      building[u][v] = 0;
      building[v][u] = 0;
    }
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        building[i][j] = min(building[i][j], building[i][k] + building[k][j]);

  scanf("%d", &t);
  while(t--){
    int s, e;
    scanf("%d %d", &s, &e);
    printf("%d\n", building[s][e]);
  }

  return 0;
}
