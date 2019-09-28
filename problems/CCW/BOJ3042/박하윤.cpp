// CCW_3042_트리플렛

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> >  value;
char in[101][101];

bool CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c){
  int op = a.first*b.second + b.first*c.second + c.first*a.second;
  op -= (a.second*b.first + b.second*c.first + c.second*a.first);
  if(op == 0) return true;
  else return false;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++){
      scanf(" %1c", &in[i][j]);
      if('A' <=  in[i][j] && in[i][j] <= 'Z') value.push_back({ i,j });
    }
  int vSize = value.size();
  int cnt = 0;
  for(int i = 0; i < vSize; i++){
    for(int j = i+1; j < vSize; j++){
      for(int k = j+1; k < vSize; k++){
        if(CCW(value[i], value[j], value[k])) cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
