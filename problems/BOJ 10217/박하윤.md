// Dijk_10217

- 내가 이해한 문제 내용
	- 총 지원비용 내에서 최소비용으로 A에서 B 갈 수 있는 노선을 찾는 프로그램

- 입력 
	- 테스트 케이스, 공항의 수, 총 지원비용, 티켓정보의 수, 각 티켓에 따른 출발 도착 공항, 비용, 소요시간
- 출력 : 가장 짧은 소요시간, 갈 수 없다면(지원비용을 초가하는 경우) poor KCM 출력

- 접근방식
	- 처음에는 DFS로 하나씩 들어가서 비용의 합을 계산하고 그 가운데에서 min을 통해 가장 적은 최소비용을 구하는 방식을 생각했었는데 정모시간에 나눈 이야기로 DFS는 최단거리를 구하지 못하기에 다익스트라를 사용해야 한다고 함
	- 조건 2개(시간과 비용)을 모두 만족 시켜야 하므로 dp도 사용
		1. 가장 짧은 소요시간
		2. 지원비용 내에서 비용이 들어야함
	- dp(i, k) = i번 노드까지 k의 비용으로 갔을 때의 최소 시간
	- 풀이와 코드 구현을 봄

- 어려웠던 점
	- 조건이 두개 였던 점
	- 여러 다른 조건들 ex) 현재의 dp에 담긴 값 (시간)은 현재시간+다음시간 값보다 작거나 같다.  와 같은 부분들을 당연하지만 생각하지 못해서 구현부분에서 자주 놓지는 것 같다 => 종이에 적고 시작하자 

```
      if(cost + next.cost > money) continue;
      if (dp[next.curr][cost + next.cost] <= curTime + next.time) continue;
```
 
```
for(int i = 0; i < adj[pos].size(); i++){
	node& next = adj[pos][i];
      .
      .
      .
bool operator < (const node& p) const {
    if(this->time == p.time) return this->cost > p.cost;
    return this->time > p.time;
  }
```

- 위의 두 부분이 이해되지 않는다.. 

- 배운점 (신기한점..)
	- 아래와 같이 top를 사용 것(pop도 그렇고 다른 벡터의 함수들 대부분) 을 처음 봄 => struct내의 변수를 꺼내서 쓸 때는 가능한건가..?

```	
	int cost = top.cost;
   int curTime = top.time;
    int pos = top.curr;
 ```
 
 - pq = {}; => 우선순위큐 초기화 무조건 필요!! 안쓰니까 틀렸다고..(초기화 관련 알아보기)

- 시간복잡도 :  O(Elog(V)) => 다익스트라의 시간복잡도