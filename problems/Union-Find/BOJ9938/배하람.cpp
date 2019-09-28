#include <cstdio>
#include <cstring>
using namespace std;

struct box{int a,b;};
const int SIZE = 300001;
int p[SIZE],r[SIZE],drawer[SIZE];
box info[SIZE];
int N,L;

int find(int v) {
  if(v == p[v]) return v;
  return p[v] = find(p[v]);
}

void uni(int v1, int v2) {
  puts("LADICA");
  int p1 = find(v1), p2 = find(v2);
  if(p1 == p2) return;
  p[p1] = p2;
}

int main(void)
{
  scanf("%d%d",&N,&L);
  for(int i=1; i<=N; i++)
    scanf("%d%d",&info[i].a,&info[i].b);
  for(int i=1; i<=L; i++){
    drawer[i] = -1;
    p[i] = i;
  }
  for(int i=1; i<=N; i++){
    int ai = info[i].a, bi = info[i].b;
    if(drawer[ai] == -1) {
      drawer[ai] = i;
      uni(ai,bi);
    }
    else if(drawer[bi] == -1) {
      drawer[bi] = i;
      uni(bi,ai);
    }
    else if(drawer[find(ai)] == -1) {
      drawer[find(ai)] = i;
      uni(ai,bi);
    }
    else if(drawer[find(bi)] == -1) {
      drawer[find(bi)] = i;
      uni(bi,ai);
    }
    else puts("SMECE");
  }
  return 0;
}