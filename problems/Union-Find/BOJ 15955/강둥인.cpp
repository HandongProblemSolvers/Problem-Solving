#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
typedef pair<int,int> pii;

//정점들을 합치기 위한 유니온 파인드
const int MAX = 251234;
int parent[MAX];
bool ans[MAX];
int find(int a){
	if(parent[a]<0) return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a==b) return;
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a];
	parent[a] = b;
}

int n, m;
vector<pii> coord;
vector<int> xsort, ysort;
priority_queue<pair<int,pii>> Q; //{-가중치, {a,b}}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(parent, -1, sizeof(parent));

	cin >> n >> m;
	for(int i=0; i<n; ++i){
		int a, b;
		cin >> a >> b;
		coord.push_back({a,b});
		xsort.push_back(i);
		ysort.push_back(i);
	}

	//xsort에 x좌표가 작은 순서대로 인덱스가 저장된다
	sort(xsort.begin(), xsort.end(), [&](int &a, int &b){
		if(coord[a].xx != coord[b].xx)
			return coord[a].xx < coord[b].xx;
		return coord[a].yy < coord[b].yy;
	});

	//ysort에 y좌표가 작은 순서대로 인덱스가 저장된다
	sort(ysort.begin(), ysort.end(), [&](int &a, int &b){
		if(coord[a].yy != coord[b].yy)
			return coord[a].yy < coord[b].yy;
		return coord[a].xx < coord[b].xx;
	});

	//우선순위 큐에 간선들을 {-가중치, {a,b}} 형태로 집어넣는다.
	for(int i=0; i<n-1; ++i){
		int a = xsort[i], b = xsort[i+1];
		Q.push({-abs(coord[a].xx - coord[b].xx), {a,b}});
	}
	for(int i=0; i<n-1; ++i){
		int a = ysort[i], b = ysort[i+1];
		Q.push({-abs(coord[a].yy - coord[b].yy), {a,b}});
	}

	//쿼리를 {{가중치, {A, B}}, 쿼리의 번호}로 저장하고,
	//가중치의 오름차순으로 정렬한다
	vector<pair<pair<int, pii>,int>> query;
	for(int i=0; i<m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		query.push_back({{c,{a,b}},i});
	}
	sort(query.begin(), query.end());

	for(auto &iiii : query){
		auto &iii = iiii.first;
		int c = iii.first, a = iii.second.first, b = iii.second.second;

		//큐에서 현재 가중치보다 작거나 같은 간선이 있으면, 꺼내서 합쳐준다.
		while(!Q.empty()){
			int cc = -Q.top().first;
			if(cc > c) break;
			merge(Q.top().second.xx, Q.top().second.yy);
			Q.pop();
		}
		ans[iiii.second] = (find(a) == find(b));
	}
	for(int i=0; i<m; ++i)
		cout << (ans[i] ? "YES\n" : "NO\n");
}
