// 4343_Arctic Network
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define SQ(x) ((x)*(x))
using namespace std;

const int max_P = 501;
const int max_V = 501*500/2;
int N, S, P, vSize, parent[max_P];
pair<int, int> pos[max_P];  // 좌표
pair<double, pair<int, int>> v[max_V]; //pair.first -> pair.second 사이의 거리

double dis(pair<int, int> &a, pair<int, int> &b){
  return sqrt((double(SQ(b.first - a.first))) + (double(SQ(b.second - a.second))));
}

int find(int x){
  if(parent[x] == -1) return x;
  return parent[x] = find(parent[x]);
}

bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return false;
  else {
    parent[y] = x;
    return true;
  }
}

int main(){
  scanf("%d", &N);
  while(N--){
    memset(parent, -1, sizeof(parent));
    memset(v, -1, sizeof(v));
    scanf("%d %d",&S, &P);
    for(int i = 0; i < P; i++)
      scanf("%d %d", &pos[i].first, &pos[i].second);

    vSize = (P*(P-1))/2;

    for(int i = 0, e = 0; i < P; i++){
      for(int j = i+1; j < P; j++, e++){
        v[e].first = dis(pos[i], pos[j]);
        v[e].second.first = i;
        v[e].second.second = j;
      }
    }

    sort(v, v+vSize);
    double ans = 0;
    for(int i = 0; i < vSize; i++){
      if(P-S == 0) break; // 인공위성의 갯수와 부대의 갯수가 같은 경우
      int a = v[i].second.first;
      int b = v[i].second.second;
      if(!merge(a,b))  continue;
      P--;
      ans = v[i].first;
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
