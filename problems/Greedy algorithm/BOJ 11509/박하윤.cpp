// 풍선맞추기_11509
#include <cstdio>
using namespace std;
int N, arrow[100001];

int main(){
  int cnt = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int H;
    scanf("%d", &H);
    if(!arrow[H+1]) {
      arrow[H]++; cnt++;
    } else{
      arrow[H+1]--; arrow[H]++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
