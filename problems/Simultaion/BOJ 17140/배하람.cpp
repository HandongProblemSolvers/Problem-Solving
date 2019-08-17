#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct nn { int num,count; };
struct cmp {
  bool operator()(const nn& n1, const nn& n2) {
    if(n1.count == n2.count) return n1.num > n2.num;
    return n1.count > n2.count;
  }
};
int r,c,k;
int a[101][101],aa[101][101];
int rc[101][101],cc[101][101],vi[101];
priority_queue<nn,vector<nn>,cmp> pq;

int main(void)
{
  scanf("%d%d%d",&r,&c,&k);
  for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      scanf("%d",&a[i][j]);
    }
  }

  int sec = 0, row = 3, col = 3;
  while(a[r][c] != k && sec <= 100) {
    for(int i=1; i<=row; i++){
      for(int j=1; j<=col; j++){
        if(!a[i][j]) continue;
        rc[i][a[i][j]]++;
        cc[j][a[i][j]]++;
      }
    }
    if(row >= col) {
      int maxCol = 0;
      for(int i=1; i<=row; i++){
        memset(vi,0,sizeof(vi));
        for(int j=1; j<=col; j++){
          if(vi[a[i][j]] || !a[i][j]) continue;
          vi[a[i][j]] = 1;
          pq.push((nn){a[i][j],rc[i][a[i][j]]});
        }
        int ii = 1, ss = pq.size()*2;
        maxCol = max(maxCol, ss);
        while(ii <= ss && ii < 100){
          nn top = pq.top(); pq.pop();
          aa[i][ii] = top.num;
          aa[i][ii+1] = top.count;
          ii += 2;
        }
      }
      for(int i=1; i<=row; i++){
        for(int j=1; j<=maxCol; j++){
          a[i][j] = aa[i][j];
        }
      }
      col = maxCol;
    } else {
      int maxRow = 0;
      for(int i=1; i<=col; i++){
        memset(vi,0,sizeof(vi));
        for(int j=1; j<=row; j++){
          if(vi[a[j][i]] || !a[j][i]) continue;
          vi[a[j][i]] = 1;
          pq.push((nn){a[j][i],cc[i][a[j][i]]});
        }
        int ii = 1, ss = pq.size()*2;
        maxRow = max(maxRow, ss);
        while(ii <= ss && ii < 100){
          nn top = pq.top(); pq.pop();
          aa[ii][i] = top.num;
          aa[ii+1][i] = top.count;
          ii += 2;
        }
      }
      for(int i=1; i<=maxRow; i++){
        for(int j=1; j<=col; j++){
          a[i][j] = aa[i][j];
        }
      }
      row = maxRow;
    }
    memset(aa,0,sizeof(aa));
    memset(rc,0,sizeof(rc));
    memset(cc,0,sizeof(cc));
    sec++;
  }

  printf("%d\n",sec>100?-1:sec);
  return 0;
}