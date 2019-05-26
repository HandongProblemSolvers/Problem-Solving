// baekjoon 3860 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};
const int MAX_W=31;
const int MAX_SIZE=MAX_W*MAX_W;
const int MAX_INF=1e9;

int W, H, G, X, Y, E, X1, X2, Y1, Y2, T, board[MAX_W][MAX_W];
int dist[MAX_SIZE];
vector<vector<pair<int,int> > > adj;

inline int incode(const int &x, const int &y) {
	return x+y*W;
}

inline pair<int, int> decode(const int &code) {
	return make_pair(code/W, code%W);
}

int main() {
	while (1) {
		memset(board, 0, sizeof(board));
		scanf("%d%d", &W, &H);
		if (!W && !H) break;
		adj = vector<vector<pair<int, int> > >(W*H);
		scanf("%d", &G);
		for (int i=0; i<G; i++) {
			scanf("%d%d", &X, &Y);
			board[X][Y] = -1;
		}
		scanf("%d", &E);
		for (int i=1; i<=E; i++) {
			scanf("%d%d%d%d%d", &X1, &Y1, &X2, &Y2, &T);
			board[X1][Y1] = 1; // it can be there, but do not generate output flow [ 1 ]
			adj[incode(X1, Y1)].push_back(make_pair(incode(X2, Y2), T));
		}
		board[W-1][H-1] = 1;

		for (int i=0; i<W; i++) {
			for (int j=0; j<H; j++) {
				if (board[i][j]) continue;
				for (int d=0; d<4; d++) {
					int nx = i + dir[d][0];
					int ny = j + dir[d][1];
					if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
					if (board[nx][ny] == -1) continue;
					adj[incode(i, j)].push_back(make_pair(incode(nx, ny), 1));
				}
			}
		}

		fill(dist, dist+W*H, MAX_INF);
		dist[0]=0;
		bool minusCycle = false;
		for (int i=0; i<W*H; i++) {
			for (int j=0; j<W*H; j++) {
				if (dist[j] == MAX_INF	) continue;
				for (int k=0; k<adj[j].size(); k++) {
					int nx = adj[j][k].first;
					int nw = adj[j][k].second;	
					if (dist[nx] > dist[j] + nw) {
						dist[nx] = dist[j] + nw;
						if (i == W*H-1) minusCycle=true;
					}
				}
			}
		}

		if (minusCycle) {
			puts("Never");
			continue;
		}
		if (dist[W*H-1] == MAX_INF) {
			puts("Impossible");
			continue;
		}
		printf("%d\n", dist[W*H-1]);
	}
	return 0;
}