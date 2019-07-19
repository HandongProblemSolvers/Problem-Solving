// DP_성냥개비_3687

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int required[10] = {6,2,5,5,4,5,6,3,7,6}; // 0~9 필요한 성냥개비 갯수
int dp[101][101];

bool match(int n, int k, bool isFirst){
  int &ret = dp[n][k];
  if(ret != -1) return ret;
  if(n == 0 && k == 0) return ret = 1;
  if(n == 1 || k == 0) return ret = 0;

  int s = isFirst ? 1 : 0;  // 처음자릿수?
  for(int i = s; i < 10; i++){
    if(n >= required[i]){
      if(match(n-required[i], k-1, false)) ret = 1;
    }
  }
  return ret = 0;
}

void trackMin(int n, int k, bool isFirst){
  if(n == 0) return;
  int s = isFirst ? 1 : 0;  
  for(int i = s; i < 10; i++){
    if(n >= required[i] && match(n-required[i], k-1, false)){
      printf("%d",i);
      trackMin(n-required[i], k-1, false);
      break;
    }
  }
}

int main(){
  int t;
  int num;
  scanf("%d", &t);
  while(t--){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &num);

    int digit = (num%7 == 0) ? num/7 : (num/7)+1; // 최소의 자릿수
    trackMin(num, digit, true);
    printf(" ");
    // 최대 큰 수 => 자릿수가 높은것으로 7 혹은 1 시작이고 나머지는 모두 1 => 1을 만드는데 필요한 성냥의 갯수가 제일 작으므로
    if(num%2 == 0){
      for(int i = 0; i < num/2; i++)
        printf("1");
    } else {
      printf("7");
      for(int i = 1; i < num/2; i++)
        printf("1");
    }
    printf("\n");
  }
  return 0;
}
