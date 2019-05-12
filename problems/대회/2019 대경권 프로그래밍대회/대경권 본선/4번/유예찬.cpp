// 대경권 본선 4.cpp
// 문제 설명
// 다이아몬드 개수 새기 ◇ << 이 모양 ㅋㅋ
// N과 N*N 크기에 board 값이 주어진다.
// board 값은 1(black)과 0(white)값이다.
// 다이아 몬드는 위와 같이 정사각형 모양에
// 45도 기울어져 있다.
// 또한 검은색으로 1겹으로 싸여 있으며,
// 안쪽은 모두 흰색으로 비어있어야 한다.

// input
// Line 1 : N
// Line 2~N+1 : N개의 board 각 줄
// output
// board에 있는 다이아몬드 총 개수

// 예제 1.
// input
// 5
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// output
// 4
// show >> D가 다이아
// 1 0 1 0 1
// 0 1 D 1 0
// 1 D 1 D 1
// 0 1 D 1 0
// 1 0 1 0 1

// 예제 2.
// input
// 8
// 0 0 0 0 0 0 0 0
// 0 0 0 1 0 1 1 0
// 0 0 1 0 1 0 0 1
// 0 1 0 1 0 1 1 0
// 1 0 0 0 1 0 0 0
// 0 1 0 1 0 1 1 0
// 0 0 1 0 1 0 1 0
// 0 1 0 1 0 0 1 0
// output
// 5
// show : D가 다이아
// 0 0 0 0 0 0 0 0
// 0 0 0 1 0 1 1 0
// 0 0 1 D 1 0 0 1
// 0 1 0 1 D 1 1 0
// 1 0 D 0 1 0 0 0
// 0 1 0 1 D 1 1 0
// 0 0 1 D 1 0 1 0
// 0 1 0 1 0 0 1 0

// 문제 풀이
// 알고리즘
// 1. 먼저 가장가리를 모두 dfs를 돌려서
// 검은색으로 둘려싸여 있는 흰색 부분을 추려 낸다.
// 2. 흰색 부분에 bfs를 돌려 다이아 인지 확인한다.
// 다이아 임을 확인하는 것을 아래와 같다.
// 2-1. 일단 흰색 크기를 샌다. 다이아의 크기는 증가수열이다.
// 변의 길이 : 1 -> 2 ->  3 ->  4 ...
// 안에 크기:  1 -> 5 -> 13 -> 25 ...
// increase :   +4   +8    +12
// accelerate: 4
// ex.
// board(1)  board(2)   board(3)       board(4)
// 0 1 0     0 0 1 0 0  0 0 0 1 0 0 0  0 0 0 0 1 0 0 0 0
// 1 D 1     0 1 0 1 0  0 0 1 0 1 0 0  0 0 0 1 0 1 0 0 0
// 0 1 0     1 0 D 0 1  0 1 0 0 0 1 0  0 0 1 0 0 0 1 0 0
//           0 1 0 1 0  1 0 0 D 0 0 1  0 1 0 0 0 0 0 1 0
//           0 0 1 0 0  0 1 0 0 0 1 0  1 0 0 0 D 0 0 0 1
//                      0 0 1 0 1 0 0  0 1 0 0 0 0 0 1 0
//                      0 0 0 1 0 0 0  0 0 1 0 0 0 1 0 0
//                                     0 0 0 1 0 1 0 0 0
//                                     0 0 0 0 1 0 0 0 0
           
// 위 크기를 만족하면 일단 다이아 모양 일 수 있음이다.
// 2-2. 이제 다이아 속의 조건을 주변의 흰색 개수를 새어보자
// ex.
// board(1)  board(2)   board(3)       board(4)
// 0 1 0     0 0 1 0 0  0 0 0 1 0 0 0  0 0 0 0 1 0 0 0 0
// 1 D 1     0 1 0 1 0  0 0 1 0 1 0 0  0 0 0 1 0 1 0 0 0
// 0 1 0     1 0 D 0 1  0 1 0 0 0 1 0  0 0 1 0 0 0 1 0 0
//           0 1 0 1 0  1 0 0 D 0 0 1  0 1 0 0 0 0 0 1 0
//           0 0 1 0 0  0 1 0 0 0 1 0  1 0 0 0 D 0 0 0 1
//                      0 0 1 0 1 0 0  0 1 0 0 0 0 0 1 0
//                      0 0 0 1 0 0 0  0 0 1 0 0 0 1 0 0
//                                     0 0 0 1 0 1 0 0 0
//                                     0 0 0 0 1 0 0 0 0
//
// adj(1)    adj(2)       adj(3)       adj(4)
// 0 0 0     0 0 0 0 0  0 0 0 0 0 0 0  0 0 0 0 0 0 0 0 0
// 0 1 0     0 0 2 0 0  0 0 0 2 0 0 0  0 0 0 0 2 0 0 0 0
// 0 0 0     0 2 5 2 0  0 0 3 5 3 0 0  0 0 0 3 5 3 0 0 0
//           0 0 2 0 0  0 2 5 5 5 2 0  0 0 3 5 5 5 3 0 0
//           0 0 0 0 0  0 0 3 5 3 0 0  0 2 5 5 5 5 5 2 0
//                      0 0 0 2 0 0 0  0 0 3 5 5 5 3 0 0
//                                     0 0 0 3 5 3 0 0 0
//                                     0 0 0 0 2 0 0 0 0
// 자 분석하자.
// - size 1 인 경우는 항상 다이아 모양이다. 
// - 1. 모든 다이아 모양은 꼭지점이 존재하므로 adj의 2의 개수는 항상 4개이다.
// - 2. adj의 4인 경우는 존재하지 않는다.
// - 3. adj의 3의 개수는 board(N)이라고 할때, 4*N-8개 이다. (잘 보면 모임 가장가리)
// 위 3가지 조건과 다이아 크기 조건을 만족하면 다이아 모양이다.

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int N, board[MAX_N][MAX_N], ret;
bool visited[MAX_N][MAX_N];

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
	if (board[x][y]) return;
	if (visited[x][y]) return;
	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
		if (visited[nx][ny]) return;
		visited[nx][ny]=true;
		dfs(nx, ny);
	}
}

bool bfs(int sx, int sy) {
	int size = 0;
	int num[6] = {0};
	queue<pair<int,int>> q;
	visited[sx][sy] = true;
	q.push({sx,sy});
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int x = q.front().first;
			int y = q.front().second;
			size++;
			int count = 0;
			for (int d=0; d<4; d++) {
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];
				if (board[nx][ny]) count++;
			}
			num[count]++;
			for (int d=0; d<4; d++) {
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];
				if (board[nx][ny]) continue;
				if (visited[nx][ny]) continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
	}
	if (size == 1) return true;
	if (num[4]) return false;
	if (num[2] != 4) return false;
	int ac = 4;
	int inc = 4;
	int tmp = 5;
	while (tmp <= size) {
		if (tmp == size) {
			if (num[3] != inc-4) return false;
			return true;
		}
		inc += ac;
		tmp += inc;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i=0; i<N; i++) {
		dfs(i, 0);
		dfs(i, N-1);
		dfs(0, i);
		dfs(N-1, i);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (visited[i][j] || board[i][j]) continue;
			if (bfs(i, j)) ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}