// 대경권 1.cpp
// 문제 설명
// 롤러코스터[https://www.acmicpc.net/problem/2873] 변형 문제
// 위 문제에서 최고의 기쁨만 출력하면 된다. (경로 필요 없음)

// - input
// Line 1: N, M (세로, 가로)
// Line 2~N : M개의 각 좌표 값

// 예제 1.
// - input
// 3 3
// 5 1 3
// 2 4 8
// 1 1 2
// - output
// 27

// 예제 2.
// - input
// 2 2
// 1 3
// 5 2
// - ouput
// 8

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

int N, M, board[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);

	int ret = 0, minV = 1e9;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &board[i][j]);
			ret += board[i][j];
		}
	}

	if (N%2 == 0 && M%2 == 0) {
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				if ( (i+j)%2 == 1)
					minV = min(minV, board[i][j]);
	}
	else minV = 0;

	printf("%d\n", ret-minV);
	return 0;
}