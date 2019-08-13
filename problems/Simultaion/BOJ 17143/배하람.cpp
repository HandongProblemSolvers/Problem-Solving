#include <cstdio>
#include <vector>
using namespace std;

struct shark{int s,d,z;};
struct pos{int x,y;};
shark ss[101][101],rr[101][101];
vector<pos> pp;
int a[101][101];
int R,C,M;
int r,c,s,d,z,ans;

int main(void)
{
  scanf("%d%d%d",&R,&C,&M);
  for(int i=1; i<=M; i++){
    scanf("%d%d%d%d%d",&r,&c,&s,&d,&z);
    ss[r][c] = (shark){s,d,z};
    pp.push_back((pos){r,c});
  }
  for(int i=1; i<=C; i++){
    int ci,cj;
    for(int j=1; j<=R; j++){
      if(ss[j][i].d){
        ans += ss[j][i].z;
        ci = j, cj = i;
        break;
      }
    }
    for(int j=0; j<pp.size(); j++){
      int _x = pp[j].x;
      int _y = pp[j].y;
      if(_x == ci && _y == cj) continue;
      int _s = ss[_x][_y].s;
      int _d = ss[_x][_y].d;
      int _z = ss[_x][_y].z;
      int _ss = _s;
      
      if(_d == 1 || _d == 2){
        while(_s){
          if(_d == 1){
            if(_x == 1) {
              _d = 2;
              continue;
            }
            _x--;
          } else{
            if(_x == R) {
              _d = 1;
              continue;
            }
            _x++;
          }
          _s--;
        }
      } else {
        while(_s){
          if(_d == 3){
            if(_y == C) {
              _d = 4;
              continue;
            }
            _y++;
          } else{
            if(_y == 1) {
              _d = 3;
              continue;
            }
            _y--;
          }
          _s--;
        }
      }
      if(rr[_x][_y].z < _z)
        rr[_x][_y] = (shark){_ss,_d,_z};
    }
    pp.clear();
    for(int i=1; i<=R; i++){
      for(int j=1; j<=C; j++){
        if(rr[i][j].d) pp.push_back((pos){i,j});
        ss[i][j] = rr[i][j];
        rr[i][j] = (shark){0,0,0};
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}