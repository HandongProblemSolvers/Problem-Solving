// BF_월드컵_6987

#include <cstdio>
#include <vector>
using namespace std;

int actuals[6][3], scores[6][3];
int team[6][3], ans;
vector<pair <int, int> > teams;

void check(int count){
    if(count == 15){
      for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
          if(scores[i][j] != actuals[i][j])  return;
      ans = 1;
      return;
  }

    int t1 = teams[count].first, t2 = teams[count].second;

    actuals[t1][0]++; actuals[t2][2]++;
    check(count+1);
    actuals[t1][0]--; actuals[t2][2]--;
    actuals[t1][2]++; actuals[t2][0]++;
    check(count+1);
    actuals[t1][2]--; actuals[t2][0]--;
    actuals[t1][1]++; actuals[t2][1]++;
    check(count+1);
    actuals[t1][1]--; actuals[t2][1]--;
}

int main(){
  for(int i = 0; i < 6; i++)
    for(int j = i+1; j< 6; j++)
      teams.push_back(make_pair(i, j));

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 6; j++){
      for(int k = 0; k < 3; k++){
        scanf("%d", &scores[j][k]);
        actuals[j][k] = 0;
      }
    }
      check(0);
      printf("%d\n", ans);
      ans = 0;
  }
  return 0;
}
