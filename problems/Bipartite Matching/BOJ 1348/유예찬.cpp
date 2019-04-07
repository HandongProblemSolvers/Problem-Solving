// baekjoon 1348 yechan
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_INF=1e9;
const int MAX_N=51;
const int MAX_CAR=101;
const int MAX_PARK=101;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

typedef pair<int, int> P;

int R, C, num_car, num_park;
P Cars[MAX_CAR], Parking[MAX_PARK];
P numCars[MAX_CAR];
int A[MAX_CAR], B[MAX_PARK];

map<P, int> keyPark;
char board[MAX_N][MAX_N];

vector<P> dist[MAX_CAR]; // [car][park]
bool carVisited[MAX_CAR];
bool visited[MAX_N][MAX_N];

void findDist(int idx) {
	memset(visited, 0, sizeof(visited));
	int sx, sy, cx, cy;
	sx = Cars[idx].first, sy = Cars[idx].second;
	queue<P> q;
	q.push(P(sx, sy));
	visited[sx][sy] = true;
 
	int depth = 1;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			cx = q.front().first, cy = q.front().second;
			q.pop();
			for (int d=0; d<4; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (visited[nx][ny]) continue;
				if (board[nx][ny] == 'X') continue;
				visited[nx][ny]=true;
				if (board[nx][ny] == 'P') dist[idx].push_back(P(keyPark.find(P(nx,ny))->second,depth));
				q.push(P(nx, ny));
			}
		}
		depth++;
	}
}

bool dfs(int here, int k) {
	carVisited[here] = true;
	for (int i=0; i < dist[here].size(); i++) {
		if (dist[here][i].second > k) continue;
		int there = dist[here][i].first;
		if (B[there] == -1 || !carVisited[B[there]] && dfs(B[there], k)) {
			A[here] = there;
			B[there] = here;
			return true;
		}
	}
	return false;
}

bool allDfs(int k) {
	fill(A, A+MAX_CAR, -1);
	fill(B, B+MAX_PARK, -1);
	for (int i=0; i<num_car; i++) {
		if (A[i] == -1) {
			memset(carVisited, 0, sizeof(carVisited));
			if (!dfs(i, k)) return false;
		}
	}
	return true;
}

int main() {
	memset(dist, MAX_INF, sizeof(MAX_INF));
	scanf("%d%d", &R, &C);
	for (int i=0; i<R; i++) {
		scanf("%s", board[i]);
		for (int j=0; j<C; j++) {
			if (board[i][j] == 'C') {
				Cars[num_car].first = i;
				Cars[num_car].second = j;
				num_car++;
			}
			if (board[i][j] == 'P') {
				Parking[num_park].first = i;
				Parking[num_park].second = j;
				keyPark[P(i,j)] = num_park;
				num_park++;
			}
		}
	}

	// There is no car.
	if (!num_car) return !printf("0\n");

	for (int i=0; i<num_car; i++) findDist(i);

	int ret = MAX_INF;
	int left = 0, right = MAX_INF;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (allDfs(mid)) right=mid-1, ret=min(ret, mid);
		else left=mid+1;
	}
	if (ret == MAX_INF) printf("-1\n");
	else printf("%d\n", ret);

	return 0;
}