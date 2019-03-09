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

int N, Q, parent[MAX_N], r[MAX_N], ans[MAX_N];
query qry[MAX_N];
coord xSort[MAX_N], ySort[MAX_N];
priority_queue < pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

int find(int n){
	if(parent[n] == -1) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

//아직 제대로 모르겠어서 내일 다시 확인할 예정인 부분. 하람이형의 풀이를 참조했음.
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(parent[a] < parent[b]) parent[a] += parent[b];
	else parent[b] += parent[a];
	// if(r[a] < r[b]) parent[a] = b;
	// else if(r[a] > r[b]) parent[b] = a;
	// else{
	// 	parent[a] = b;
	// 	r[b]++;
	// }
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
		r[i] = 1;
	}

	for(int i = 1; i <= Q; i++){
		int a, b, hp;
		scanf("%d %d %d", &a, &b, &hp);
		qry[i] = {hp, a, b, i};
	}

	sort(xSort+1, xSort+N+1, cmpX);
	sort(ySort+1, ySort+N+1, cmpY);
	sort(qry+1, qry+Q+1);

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
			// printf("%d\n", cur);
			printf("%d %d\n", pq.top().second.first, pq.top().second.second);
			if (cur > c) break;
			merge(pq.top().second.first, pq.top().second.second);
			pq.pop();
			// printf("%d\n", cur);
		}
		ans[qry[i].idx] = (find(a-1) == find(b-1));
	}

	for(int i = 1; i <= Q; i++){
		ans[i] ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}