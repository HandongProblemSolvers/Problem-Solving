// 컵라면_1781
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> cup;
vector< cup > ramen;
priority_queue <int> pq;

int N;
int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int num, deadline;
    scanf("%d %d", &deadline, &num);
      ramen.push_back( { deadline, num} );
  }
  sort(ramen.begin(), ramen.end());
int result = 0;
  for(int i = 0; i < N; i++){
    int deadline = ramen[i].first;
    pq.push(-ramen[i].second);

    if(deadline < pq.size())
      pq.pop();
  }
  while(!pq.empty()){
    result += pq.top();
    pq.pop();
  }
  printf("%d", -result);
}
