// Simulation_낚시왕_17143_fail..(first test case)

#include <iostream>
#include <cstring>
using namespace std;

struct Sharks{
  int r, c, s, d, z, death;
};

Sharks fish[101*101];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int R, C, M, map[101][101], ans;

void move(){ // 상어의 움직임 & 두 마리의 상어가 한 곳에 위치 할 수 없음 check
  Sharks temp[101*101] = {0};
  for(int i = 1; i <= M; i++){
    if(fish[i].death) continue;
    if(fish[i].d < 2){ // Up, down
      int s = fish[i].s % (R*2); // 제자리로 돌아오므로 나머지를 활용하여 계산
      int d = fish[i].d;
      int pos = fish[i].r;
      while(s--){
        if(pos == 1 && d == 1) d = 2; // 위치 인덱스에 따라 방향 바꿔주기
        if(pos == R && d == 2) d = 1;
        pos += dy[d]; // 위치 변경
      }
      if(temp[i].z < fish[i].z) temp[i] = {fish[i].r, fish[i].c, fish[i].s, fish[i].d,fish[i].z, fish[i].death};
    }
    else if(fish[i].d > 2){ // right, left
      int s = fish[i].s % (C*2);
      int d = fish[i].d;
      int pos = fish[i].r;
      while(s--){
        if(pos == 1 && d == 4) d = 3;
        if(pos == C && d == 3) d = 4;
        pos += dx[d];
      }
      if(temp[i].z < fish[i].z) temp[i] = {fish[i].r, fish[i].c, fish[i].s, fish[i].d, fish[i].z, fish[i].death};
    }
  }
  memcpy(fish, temp, sizeof(temp));
}

void catchSharks(){ // 상어잡기
  for(int i = 1; i <= C; i++)
    for(int j = 1; j <= R; j++){
      if(map[j][i]){
        fish[map[j][i]].death = 1;
        ans += fish[map[j][i]].z;
        map[j][i] = 0;
        break;
      }
    move();
  }
}

int main(){
  cin >> R >> C >> M;

  for(int i = 1; i <= M; i++){
    cin >> fish[i].r >> fish[i].c >>fish[i].s >> fish[i].d >> fish[i].z;
    map[fish[i].r][fish[i].c] = i;
  }
  catchSharks();

  cout << ans << endl;
  return 0;
}
