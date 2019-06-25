#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int N;
  int max_noodle = 0;

  vector <pair <int, int> > prob;
  priority_queue <int> pq;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int tmp1, tmp2;
    scanf("%d %d", &tmp1, &tmp2);
    prob.push_back(make_pair(tmp1, tmp2));
  }

  sort(prob.begin(), prob.end());

  for (int i = 0; i < N; i++) {
    int dline = prob[i].first;
    
    // 더 작은 값이 위로 가게
    pq.push(-1 * prob[i].second);

    // 데드라인보다 풀 문제가 더 들어가 있으면 그 문제는 풀지 못하는 문제
    if (dline < pq.size())
      pq.pop();
  }

  while (!pq.empty()) {
    max_noodle += pq.top();
    pq.pop();
  }

  printf("%d\n", -1 * max_noodle);
  return 0;
}
