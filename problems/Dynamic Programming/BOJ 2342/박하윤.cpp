// DP_DDR_2342
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
const int maxN = 100001;
using namespace std;

int n, vsize;
vector <int> step;
int dp[5][5][maxN]; // 왼발, 오른발, maxN

int weight(int from, int to){
  if(from == 0) return 2;
  else if(abs(from-to) == 1 || abs(from-to) == 3) return 3;
  else if(from == to) return 1;
  else return 4;
}

int solve(int x, int y, int index){
  if(index == vsize) return 0;
  if(dp[x][y][index] != -1) return dp[x][y][index];
  int left = solve(step[index], y, index+1) + weight(x, step[index]);
  int right = solve(x, step[index], index+1) + weight(y, step[index]);
  return dp[x][y][index] = min(left, right);
}

int main(){
  int result = 0;
  memset(dp, -1, sizeof(dp));
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    step.push_back(n);
  }
  vsize = step.size();
  printf("%d\n", solve(0, 0, 0));
  return 0;
}
