#include <cstdio>
#include <algorithm>
#define INF 1900000000
using namespace std;

const int MAX = 100001;

int seg[4*MAX];

int update(int pos, int val, int idx, int start, int end){
  if(pos < start || pos > end) return seg[idx];

  if(start == end)
    return seg[idx] = val;
  else{
    int mid = (start+end)/2;
    return seg[idx] = min(update(pos, val, idx*2, start, mid), update(pos, val, idx*2+1, mid+1, end));
  }
}

int tree(int idx, int left, int right, int start, int end){
  if(end < left || start > right) return INF;
  if(start >= left && end <= right) return seg[idx];
  else {
    int mid = (start+end)/2;
    return min(tree(idx*2, left, right, start, mid), tree(idx*2+1, left, right, mid+1, end));
  }
}

int main(){
  int N, M, num;
  int a, b;
  scanf("%d %d",&N, &M);
  for(int i = 1; i <= N; i++){
    scanf("%d", &num);
    update(i, num, 1, 1, N);
  }

  for(int i = 0; i < M; i++){
    scanf("%d %d", &a, &b);
    printf("%d\n",tree(1, a, b, 1, N));
  }
  return 0;
}
