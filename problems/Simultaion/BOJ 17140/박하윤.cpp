// Simulation_이배열과 연산_17140

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100;

int r, c, k;
int map[MAX][MAX];
bool flag;

void intialize(int R, int C){
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
      map[i][j] = 0;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cin >> r >> c >> k;
  r -= 1; c -= 1;
  int time = 0;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> map[i][j];
      if(i == r && j == c && k == map[i][j])
        flag = true;
    }
  }
  int R = 3, C = 3;
  while(!flag){
    time++;
    if(time > MAX){
       cout << "-1" << endl;
       return 0;
    }
    vector < pair<int, int> > num[MAX];
    // R 연산 => 행에 대하여 정렬
    if(R >= C){
      for(int i = 0; i < R; i++){
        int cnt[MAX+1] = {0};
        for(int j = 0; j < C; j++)
          cnt[map[i][j]]++;
        for(int j = 1; j <= MAX; j++)
          if(cnt[j]) num[i].push_back(make_pair(cnt[j], j));
      }

      intialize(R, C);

      for(int i = 0; i < R; i++)
        sort(num[i].begin(), num[i].end());

      for(int i = 0; i< R; i++){
        int idx = 0;
        for(int j = 0; j < num[i].size(); j++){
          map[i][idx++] = num[i][j].second;
          if(idx == MAX) break;
          map[i][idx++] = num[i][j].first;
          if(idx == MAX) break;
        }
        C = max(C, idx);
      }
    } else {
      for(int i = 0; i < C; i++){
        int cnt[MAX+1] = {0};
        for(int j = 0; j < R; j++)
          cnt[map[j][i]]++;
        for(int j = 1; j <= MAX; j++)
          if(cnt[j]) num[i].push_back(make_pair(cnt[j], j));
      }

      intialize(R, C);
      for(int i = 0; i < C; i++)
        sort(num[i].begin(), num[i].end());

      for(int i = 0; i < C; i++){
        int idx = 0;
        for(int j = 0; j < num[i].size(); j++){
          map[idx++][i] = num[i][j].second;
          if(idx == MAX) break;
          map[idx++][i] = num[i][j].first;
          if(idx == MAX) break;
        }
        R = max(R, idx);
      }
    }
    if(map[r][c] == k) {
      flag = true;
      break;
    }
  }
  cout << time << endl;
  return 0;
}
