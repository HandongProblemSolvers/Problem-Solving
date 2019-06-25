// BS_7453_합이0
#include <cstdio>
#include <algorithm>
using namespace std;
const int max_n = 4001;

int main(){
  int n;
  long A[max_n], B[max_n], C[max_n], D[max_n];
  long long AB[max_n*2], CD[max_n*2];
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    scanf("%ld %ld %ld %ld", A+i, B+i, C+i, D+i);

  int idx = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      AB[idx] = A[i] + B[j];
      CD[idx++] = C[i] + D[j];
    }
  }
  sort(CD, CD + n*n); // 기준만 정렬

  long long cnt = 0;
  long left = 0, right = n*n;

  for(int i = 0; i < n*n; i++){
    while(left < right){
      long mid = (left + right) / 2;
      if(AB[i] + CD[mid] < 0) left = mid + 1;
      else right = mid;
    }
    long lower_bound = right;

    left = 0, right = n*n;
    while(left < right){
      long mid = (left+right)/2;
      if(AB[i] + CD[mid] <= 0) left = mid + 1;
      else right = mid;
    }
    long upper_bound = right;

    cnt += (upper_bound - lower_bound);
    left = 0, right = n*n;
  }
  printf("%lld", cnt);
  return 0;
}
