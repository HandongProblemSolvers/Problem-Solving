// 정렬_17074

#include <cstdio>

int main(){
  int N;
  scanf("%d", &N);

  int arr[N+1];
  arr[0] = -1000000001;
  arr[N+1] = 1000000001;
  int cnt = 0, ans = 0, prev = 0, post = 0;

  for(int i = 1; i <= N; i++){
    scanf("%d", arr+i);

    if(arr[i] < arr[i-1]){
      cnt++;
      prev = i - 1;
      post = i;
    }
  }

  if(cnt == 0) ans = N;
  else if(cnt > 1) ans = 0;
  else {
    if(arr[prev-1] <= arr[post]) ans++;
    if(arr[prev] <= arr[post+1]) ans++;
  }
  printf("%d\n", ans);
}
