// queue_톱니바퀴_14891_compileError

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

deque<int> wheel[5];
bool visited[5]; // 여러번 돌아가는걸 방지
vector<pair <int, int> > info;

void rotate(int at, int direction){
  // 시계방향
  if(direction == 1){
    int temp = wheel[at].back();
    wheel[at].pop_back();
    wheel[at].push_front(temp);
  }
  // 반시계방향
  else if(direction == -1){
    int temp = wheel[at].front();
    wheel[at].pop_front();
    wheel[at].push_back(temp);
  }
}

void solution(int at, int direction){
  visited[at] = true;

  int next = at + 1;
  int pre = at - 1;
  if(next < 5 && wheel[at][2] != wheel[next][6] && !visited[next])
    solution(next, direction * -1);

  if(pre > 0 && wheel[at][6] != wheel[pre][2] && !visited[pre])
    solution(pre, direction * -1);

  rotate(at, direction);
}

int main(){
  // poles 입력받기
  for(int i = 0; i < 4; i++){
    string poles;
    scanf("%s", poles);
    for(int j = 0; j < 8; j++){
      int pole = poles[j] - '0';
      wheel[i+1].push_back(pole);
    }
  }

  int K, answer = 0;
  scanf("%d", &K);
  for(int i = 0; i < K; i++){
    int wheelNum, direction;
    scanf("%d %d",&wheelNum, &direction);
    info.push_back(make_pair(wheelNum, direction)); // 여기서부터가 문제..
  }

  for(int i = 0; i < info.size(); i++){
    memset(visited, false, sizeof(visited));
    solution(info[i].first, info[i].second);
  }
  for(int i = 1; i < 5; i++){
    if(wheel[i][0] == 1){
      answer += pow(2, i-1);
    }
  }
  printf("%d\n", answer);
  return 0;
}
