//BOJ 15955 부스터(카카오 코드 페스티벌 2018 예선 D번)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 250001
typedef pair<int, int> P;

struct query{
	int w, a, b, idx;

	bool operator<(const query& q){
		return w < q.w;
	}
};

struct coord{
	int x, y, idx;

	bool operator<(const coord& c){
		return x < c.x;
	}
};

int N, Q, parent[MAX_N], ans[MAX_N];
query qry[MAX_N];
coord xSort[MAX_N], ySort[MAX_N];
priority_queue < pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

int find(int n){
	if(parent[n] == -1) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	//둘의 부모가 같을 경우 or 둘 다 root
	if(parent[a] == parent[b]) parent[b] = a;
	//집합의 크기를 자식에게 계속 넘겨줌.
	else{
		parent[a] += parent[b];
		parent[b] = a;
	}
	return;
}

bool cmpX(coord a, coord b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool cmpY(coord a, coord b){
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int main(){
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		xSort[i] = {a, b, i};
		ySort[i] = {a, b, i};
	}

	for(int i = 1; i <= Q; i++){
		int a, b, hp;
		scanf("%d %d %d", &a, &b, &hp);
		qry[i] = {hp, a, b, i};
	}

	//x좌표 기준과 y좌표 기준, hp기준으로 각각 sort
	sort(xSort+1, xSort+N+1, cmpX);
	sort(ySort+1, ySort+N+1, cmpY);
	sort(qry+1, qry+Q+1);

	//pq에 비용과 노드 번호를 push
	for(int i = 1; i < N; i++){
		int a = xSort[i].idx;
		int b = xSort[i+1].idx;
		pq.push({xSort[i+1].x - xSort[i].x , {a,b}});
		// printf("x: %d %d %d\n", a, b, xSort[i+1].x - xSort[i].x);
	}

	for(int i = 1; i < N; i++){
		int a = ySort[i].idx;
		int b = ySort[i+1].idx;
		pq.push({ySort[i+1].y - ySort[i].y, {a,b}});
		// printf("y: %d %d %d\n", a, b, ySort[i+1].y - ySort[i].y);
	}

	memset(parent, -1, sizeof(parent));
	for(int i = 1; i <= Q; i++){
		int a = qry[i].a;
		int b = qry[i].b;
		int c = qry[i].w;
		// printf("%d %d %d\n", a, b, c);
		while(!pq.empty()){
			int cur = pq.top().first;
			//비용이 c보다 크면 안됨
			if (cur > c) break;
			//두 정점을 union-find
			merge(pq.top().second.first, pq.top().second.second);
			pq.pop();
			// printf("%d\n", cur);
		}
		/*
		두 정점이 유니온파인드를 통해 이어졌는지 확인. 비용이 c이하인 애들을 확인.
		sorting을 한 순서대로 확인하고 정답은 질문한 순서대로 출력해야해서 index를 저장했었음. */
		ans[qry[i].idx] = (find(a) == find(b));
	}

	for(int i = 1; i <= Q; i++){
		ans[i] ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}