// 대경권 본선 3.cpp
// 문제설명:
// A와 B 플레이어가 있다.
// 게임은 코인 2종류가 a,b개 있다.
// A부터 시작해서 서로 돌아가면서 게임을 진행한다.
// 게임의 규칙은 다음과 같다.
// - 두 코인이 없는 경우 상대플레이어가 이긴다.
// - 한 종류의 코인을 선택하고, 코인을 1개 이상 뽑는다.
// - 또는, 두 종류의 코인을 똑같은 개수 1개 이상 뽑는다.
// 항상 플레이어는 최선을 다한다.
// 자기가 이기는 경우 최대한 빠르게 이기며,
// 자기가 지는 경우 최대한 느리게 지려고한다.

// 복귀 및 문제 풀이:
// 문제 풀이는 DP 임을 알고 다시 생각하고 풀었다.
// 알고리즘은 다음과 같다.
// - 이기는 경우는 return 값과 현재 count차가 홀수인 경우 이다.
// - return 값이 짝수인 경우 B가 이기고, 홀수인 경우 A가 이김

// Comment: 하 결국 DP가 이걸... (못푼 문제) 처음에 BFS하고 Greedy Algorihtm 인줄 알고 Optimal 찾다 망함. \o/

// input : a, b (0 ~ 100)

// 예제 1.
// - input
// 0 0
// - output
// B
// 0

// 예제 2.
// - input
// 1 3
// - output
// A
// 3

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int a, b, dp[MAX_N*2][MAX_N][MAX_N];

int game(int count, int a, int b) {
	if (a == 0 && b == 0) return count;
	int &ret = dp[count][a][b];
	if (ret) return ret;
	int minV=1e9;
	int maxV=0;
	int value=0;
	// 코인 a: i개 선택 
	for (int i=1; i<=a; i++) {
		value = game(count+1, a-i, b);
		if ((value + count)%2) minV = min(minV, value);
		else maxV = max(maxV, value);
	}
	// 코인 b: i개 선택 
	for (int i=1; i<=b; i++) {
		value = game(count+1, a, b-i);
		if ((value + count)%2) minV = min(minV, value);
		else maxV = max(maxV, value);
	}
	// 코인 a, b: i개 선택
	for (int i=1; i<=min(a,b); i++) {
		value = game(count+1, a-i, b-i);
		if ((value + count)%2) minV = min(minV, value);
		else maxV = max(maxV, value);
	}
	if (minV != 1e9) return minV;
	else return maxV;
}

int main() {
	scanf("%d%d", &a, &b);
	int ret = game(0, a, b);
	if (ret%2) printf("A\n");
	else printf("B\n");
	printf("%d\n", ret);
	return 0;
}