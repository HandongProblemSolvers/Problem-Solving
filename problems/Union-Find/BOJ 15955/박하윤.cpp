#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>

#define max 250001
#define xx first
#define yy second
using namespace std;

typedef pair<int, int> P;

int N, Q;
vector <P> map;
vector <int> xSort, ySort;
priority_queue<pair <int, P> >  pq; // {-가중치, {a,b}} 
int parent[max];
bool answer[max];

int find(int a){
  if(parent[a] < 0) return a;
  return parent[a] = find(parent[a]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(parent[a] < parent[b]) swap(a, b);
  parent[b] += parent[a];
  parent[a] = b;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  memset(parent, -1, sizeof(parent));

  cin >> N >> Q;
  for(int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    map.push_back({x, y});
    xSort.push_back(i);   
    ySort.push_back(i);
  }

  // 작은거 부터 오름차순 정렬 => 반복적인 부분인데 다르게 표현 할 수 있지 않을까..?
  sort(xSort.begin(), xSort.end(), [&](int &a, int &b){
    if(map[a].xx != map[b].xx)
      return map[a].xx < map[b].xx;
    return map[a].yy < map[b].yy;
  });

  sort(ySort.begin(), ySort.end(), [&](int &a, int &b){
    if(map[a].yy != map[b].yy)
      return map[a].yy < map[b].yy;
    return map[a].xx < map[b].xx;
  });

  for(int i = 0; i < N - 1; i++){
    int a = xSort[i];
    int b = xSort[i+1];
    pq.push({-abs(map[a].xx - map[b].xx), {a,b} } );  // 절댓값에 '-' 를 취하지 않을 경우 틀렸었다
  }

  for(int i = 0; i < N-1; i++){
    int a = ySort[i];
    int b = ySort[i+1];
    pq.push({-abs(map[a].yy - map[b].yy), {a,b} } );
  }

// {{가중치, {a,b}, 쿼리의 번호}}
  vector<pair<pair<int, P>, int> > query;

  for(int i = 0; i < Q; i++){
    int a, b, c;
    cin >> a >> b >> c;
    query.push_back({{c, {a-1,b-1}}, i});
  }
  sort (query.begin(), query.end());

  for (auto &iiii : query){
    auto &iii = iiii.first;
    int c = iii.first;  // 가중치
    int a = iii.second.first; // a
    int b = iii.second.second;  // b
   

    while(!pq.empty()){
      int curC = -pq.top().first;
      // 현재 가중치보다 작거나 같은 간선이 있다면 꺼내서 합치기!
      if(curC > c)
        break;
      merge(pq.top().second.xx, pq.top().second.yy);
      pq.pop();
    }
    answer[iiii.second] = (find(a) == find(b)); 
  }
  // 결과 출력
  for(int i = 0; i < Q; i++)
      cout << (answer[i] ? "YES\n" : "NO\n");

    return 0;
}