// 대경권 5.cpp
// 문제 설명
// 강의실을 사용하려고 한다.
// N개의 강의실 대여 목록이 주어진다.
// 대여 목록은 시작시간과 종료 시간이 주어진다.
// 시작시간과 종료 시간이 s, e 라고 할때, 0< s <= e < 88888를 만족한다.
// N은 최대 100000개이다.
// 이때 사용하는 강의실이 최대인 시간을 모두 출력하라.

// input
// Line 1 : N
// Line 2~N+1 : 두 정수 start time, end time
// 출력 
// 최대 강의실 수인 시간 출력

// 예제 1.
// input
// 3
// 0 5
// 2 3
// 4 4
// output
// 2 3 4

// 문제 풀이
// Two Pointer Problem
// 항상 시작시간이 종료 시간보다 같거나 작다.
// s 배열의 시작시간을, e 배열의 종료 시간을 저장한다.
// s와 e 배열을 오름차순으로 정렬한다.
// 0초부터 88887초 까지 시뮬레이션을 한다.
// 임의에 t = (0 <= t <= 88887) 라고 할때, 
// 다음 시간에 시작될 강의실은 s[spos],
// 다음 시간에 종료될 강의실은 e[epos]이다.
// 여기서 먼저 종료될 강의실을 체크한다.
// 점화식은 e[epos] < t 임을 확인한다.
// t 시간때 위 식을 만족하는 강의실을 모두 종료한다.(epos++)
// 다음 t 시간에 시작될 모든 강의실을 체크한다.
// 점화식은 s[spos] == t 임을 확인한다.
// t  시간때 위 식을 만족하는 강의실을 모두 시작한다.(spos++)
// 위 모두 한 뒤에 지금 진행중인 강의수는 spos - epos 임을 알 수 있다.
// space[t]=spos-epos로 저장한다.
// 위 진행중인 강의 수 중에 가장 큰 값을 저장한다.
// 이 뒤에 0~88887초를 순차적으로 보면서 space[t]==maxSpace 인 경우 t를 출력한다.

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
const int MAX_T=88888;

int N, s[MAX_N], e[MAX_N], spos, epos, ret, space[MAX_T];

int main() {
	scanf("%d", &N);

	for (int i=0; i<N; i++)
		scanf("%d%d", &s[i], &e[i]);

	sort(s, s+N);
	sort(e, e+N);

	for (int t=0; t<MAX_T; t++) {
		while (e[epos] < t) epos++;
		while (s[spos] <= t) spos++;
		space[t] = spos - epos;
		ret = max(ret, spos - epos);
	}

	for (int t=0; t<MAX_T; t++)
		if (ret == space[t])
			printf("%d ", t);

	return 0;
}
