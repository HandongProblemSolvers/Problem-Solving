// baekjoon 7578 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=500001;
const int SIZE=1<<19;

int N, data[MAX_N], arr[SIZE*2];
pair<int,int> left[MAX_N], right[MAX_N];

void update(int i, int val) {
  i += SIZE;
  arr[i] = val;
  while (i > 1) {
    i/=2;
    arr[i] = arr[i*2] + arr[i*2+1];
  }
}

int sum(int left, int right, int nodeNum, int nodeL, int nodeR) {
  if (right < nodeL || nodeR < left) return 0;
  if (left <= nodeL && nodeR <= right) return arr[nodeNum];
  int mid = (nodeL + nodeR)/2;
  return sum(left, right, nodeNum*2, nodeL, mid) + sum(left, right, nodeNum*2+1, mid+1, nodeR);
}

int sum(int left, int right) {
  return sum(left, right, 1, 0, SIZE-1);
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &left[i].first);
    left[i].second = i;
  }
  for (int i=0; i<N; i++) {
    scanf("%d", &right[i].first);
    right[i].second = i;
  }
  sort(left, left+N);
  sort(right, right+N);

  for (int i=0; i<N; i++) {
    data[left[i].second] = right[i].second;
  }

  long long ret = 0;
  for (int i=0; i<N; i++) {
    ret += sum(data[i], MAX_N);
    update(data[i], 1);
  }
  printf("%lld\n", ret);
  return 0;
}