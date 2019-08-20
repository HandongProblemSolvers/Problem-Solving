// bitmask_타일채우기_2718

#include <iostream>
#include <cstring>
using namespace std;
int N;
int dp[501][13];

int fun(int n, int cur){ //n: 구해야 하는 열의 크기 cur : 현재 열의
  if(n < 0 || (n == 1 && cur == 6)) return 0; // cur이 6이고 남은 열이 1개이면 방법이 없음 => 다 못채우는 경우
  if(n == 0 || n == 1) return 1; // 1열만 존재하면 경우는 오직 1개
  int& ret = dp[n][cur];
  if(ret != -1) return ret;
  ret = 0;
  switch (cur) {
    case 0:
      ret += fun(n-1, 0);
      ret += fun(n-1, 3);
      //ret += fun(n-1, 6); // 해당열을 모두 채우면서 6 상태로 만들 수 없음!
      ret += fun(n-1, 9);
      ret += fun(n-1, 12);
      ret += fun(n-2, 0);
      break;
    case 3:
      ret += fun(n-1, 0) + fun(n-1, 12);
      break;
    case 6:
      ret += fun(n-1, 9);
      break;
    case 9:
      ret += fun(n-1, 0) + fun(n-1, 6);
      break;
    case 12:
      ret += fun(n-1, 0) + fun(n-1, 3);
      break;
  }
  return dp[n][cur] = ret;
}

int main(){
  int T;
  cin >> T;
  memset(dp, -1, sizeof(dp));
  while(T--){
    cin >> N;
    cout << fun(N, 0) << endl;
  }
  return 0;
}
