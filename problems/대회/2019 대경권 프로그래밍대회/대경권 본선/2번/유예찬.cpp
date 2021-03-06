// 대경권 2.cpp
// 문제 설명
// 각자의 간격이 일정한 N * N 개의 점들이 있다.
// 이때에 서로 다른 4점을 선택하여 만들 수 있는 정사각형 개수는?
// input : N (2 ~ 400)

// 예제 1.
// - input
// 3
// - ouput
// 6
// show : 
// . . .
// . . .
// . . .
// Equation
// 2*2 + 1*1 + (3-(1+1))*(3-(1+1))
// = 4 + 1 + 1 = 6

// 예제 2.
// - input
// 4
// - ouput
// 20
// show :
// . . . .
// . . . .
// . . . .
// . . . .
// Equation
// 3*3 + 2*2 + 1*1 +
// (4-(1+1))*(4-(1+1)) + (4-(1+2))*(4-(1+2)) +
// (4-(2+1))*(4-(2+1))
// = 9 + 4 + 1 + 4 + 1 + 1 = 20

#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
int N;
ll ret;

int main() {
	scanf("%d", &N);
	for (int i=1; i<N; i++)
		ret += i*i;

	for (int a=1; a<N; a++)
		for (int b=1; b<N-a; b++)
			ret += (N-(a+b))*(N-(a+b));

	printf("%lld\n", ret);
	return 0;
}