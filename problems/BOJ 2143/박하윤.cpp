#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int T, n, A[1001], m, B[1001];
  long long cnt = 0;
  vector <int> v1;
  vector <int> v2;

  scanf("%d", &T);

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", A+i);

  scanf("%d", &m);
  for(int i = 0; i < m; i++)
    scanf("%d", B+i);

  for(int i = 0; i < n; i++){
    int sum = A[i];
    v1.push_back(sum);
    for(int j = i+1; j < n; j++){
      sum += A[j];
      v1.push_back(sum);
    }
  }

  for(int i = 0; i < m; i++){
    int sum = B[i];
    v2.push_back(sum);
    for(int j = i+1; j < m; j++){
      sum += B[j];
      v2.push_back(sum);
    }
  }

  sort(v2.begin(), v2.end());

  for(auto fir : v1){
    int diff = T - fir;
    auto up = upper_bound(v2.begin(), v2.end(), diff); // diff 보다 큰 수가 있는 인덱스 넘버 (diff 포함하지 않고)
    auto down = lower_bound(v2.begin(), v2.end(), diff); // diff보다 작은 수가 있는 마지막 인덱스 넘버 (diff 포함)
    cnt += (up - down);
  }
  printf("%lld\n", cnt);
  return 0;
}
