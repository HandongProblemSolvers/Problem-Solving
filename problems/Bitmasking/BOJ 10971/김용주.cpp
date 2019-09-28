//BOJ10971 외판원순회2
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
int N, W[11][11], dist[11][1<<11];

int TSP(int start, int state){
	if(state == (1<<N) - 1) return W[start][0];
	if(dist[start][state] != -1) return dist[start][state];

	int a = INF;
	for(int i = 0; i < N; i++){
		if((state & (1<<i))) continue;
		if(W[start][i] == INF) continue;
		a = min(a, TSP(i, (1<<i) | state) + W[start][i]);
	}
	dist[start][state] = a;
	return dist[start][state];
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &W[i][j]);
			if(!W[i][j]) W[i][j] = INF;
		}
	}
	memset(dist, -1, sizeof(dist));
	printf("%d",TSP(0, 1));

	return 0;
}