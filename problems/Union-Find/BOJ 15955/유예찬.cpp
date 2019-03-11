// baekjoon 15955 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int MAX_N=250001;

struct Point {
	int x, y, idx;
	Point(){}
	Point(int x, int y, int idx):x(x), y(y), idx(idx){}
};

bool cmp_x(const Point &a, const Point &b) {
	return a.x < b.x;
}
bool cmp_y(const Point &a, const Point &b) {
	return a.y < b.y;
}

struct Quest{
	int A, B, HP, idx;
	Quest(){}
	Quest(int A, int B, int HP, int idx):A(A), B(B), HP(HP), idx(idx){}
	bool operator<(const Quest &o) {
		return HP < o.HP;
	}
};

struct Vertex{
	int dist, A, B;
	Vertex(){}
	Vertex(int d, int a, int b):dist(d), A(a), B(b){}
};

struct cmp_v {
	bool operator() (const Vertex &a, const Vertex &b){
		return a.dist > b.dist;
	}
};

int N, Q, X, Y, from, to, H, root[MAX_N];
bool ret[MAX_N];
Quest quest[MAX_N];
Point pointX[MAX_N], pointY[MAX_N];
priority_queue<Vertex, vector<Vertex>, cmp_v> pq;

int find(int x) {
	if (!root[x]) return x;
	return root[x]=find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[b]=a;
}

int main() {
	scanf("%d %d", &N, &Q);

	for (int i=1; i<=N; i++) {
		scanf("%d %d", &X, &Y);
		pointX[i]=Point(X, Y, i);
		pointY[i]=Point(X, Y, i);
	}
	sort(pointX+1, pointX+N+1, cmp_x);
	sort(pointY+1, pointY+N+1, cmp_y);

	for (int i=1; i<N; i++) {
		pq.push(Vertex(pointX[i+1].x-pointX[i].x, pointX[i].idx, pointX[i+1].idx));
		pq.push(Vertex(pointY[i+1].y-pointY[i].y, pointY[i].idx, pointY[i+1].idx));
	}

	for (int i=0; i<Q; i++) {
		scanf("%d %d %d", &from, &to, &H);
		quest[i]=Quest(from, to, H, i);
	}

	sort(quest, quest+Q);

	for (int i=0; i<Q; i++) {
		while (!pq.empty() && pq.top().dist <= quest[i].HP) {
			merge(pq.top().A, pq.top().B);
			pq.pop();
		}
		ret[quest[i].idx]=find(quest[i].A)==find(quest[i].B);
	}

	for (int i=0; i<Q; i++) {
		puts(ret[i] ? "YES" : "NO");
	}

	return 0;
}