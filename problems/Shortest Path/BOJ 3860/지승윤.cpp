#include <cstdio>
#include <vector>
#define x first
#define y second
using namespace std;
const int MAX_V = 905;
const int INF = 2e9;
typedef pair<pair<int, int>, int> P;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int main() {
   while (true) {
      bool chk = false;
      int W, H, G, E;
      vector<P> v;
      vector<int> GG;
      vector<P> EE;
      scanf("%d%d", &W, &H);
      if (W == 0 && H == 0) return 0;
      scanf("%d", &G);
      for (int i = 0; i < G; i++) {
         int a, b;
         scanf("%d%d", &a, &b);
         GG.push_back(b*W + a + 1);
      }
      scanf("%d", &E);
      for (int i = 0; i < E; i++) {
         int x1, y1, x2, y2, t;
         scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
         EE.push_back({ { y1*W + x1 + 1,y2*W + x2 + 1 }, t });
      }
      for (int i = 0; i < H; i++) {
         for (int j = 0; j < W; j++) {
            int a = i * W + j + 1;
            if (a == W * H) continue;
            for (int k = 0; k < 4; k++) {
               chk = false;
               if (i + dir[k][0] >= H || i + dir[k][0] < 0 || j + dir[k][1] < 0 || j + dir[k][1] >= W) continue;
               int b = (i + dir[k][0])*W + j + dir[k][1] + 1;
               for (int c : GG) if (a == c || b == c) chk = true;
               for (auto& c : EE) if(a==c.x.x) chk = true;
               if (chk) continue;
               v.push_back({ { a,b },1 });
            }
         }
      }
      for (auto &p : EE) v.push_back({ {p.x.x,p.x.y},p.y });
      int dist[MAX_V];
      fill(dist, dist + MAX_V, INF);
      dist[1] = 0;
      chk = false;
      for (int i = 0; i <MAX_V; i++) {
         for (int j = 0; j < v.size(); j++) {
            if (dist[v[j].x.x] != INF && dist[v[j].x.y] > dist[v[j].x.x] + v[j].y)
               dist[v[j].x.y] = dist[v[j].x.x] + v[j].y;
         }
      }
      for (int j = 0; j < v.size(); j++) {
         if (dist[v[j].x.x] != INF && dist[v[j].x.y] > dist[v[j].x.x] + v[j].y)
            chk = true;
      }
      if (chk) printf("Never\n");
      else dist[W*H] == INF ? printf("Impossible\n") : printf("%d\n", dist[W*H]);
   }
}
