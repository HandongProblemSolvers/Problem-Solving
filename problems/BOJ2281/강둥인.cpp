#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999
int n, m, dp[1001][1001];
vector<int> names;

int solve(int curr, int index) {
	if (index >= n)
		return 0;

	//열을 넘어가는 경우
	if (curr >= m) {
		//커서가 m이면 맨 끝에 한칸의 빈칸이 있음
		int add = (curr == m ? 1 : 0);
		return solve(names[index] + 1, index + 1) + add;
	}

	int &ret = dp[curr][index];
	if (ret != -1)
		return ret;
	ret = INF;

	//개행 시 공백 구하기
	ret = solve(names[index] + 1, index + 1) + (m - curr + 1)*(m - curr + 1);

	//이어 쓰는 경우
	if (curr + names[index] <= m)
		ret = min(ret, solve(curr + names[index] + 1, index + 1));
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	names = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &names[i]);

	memset(dp, -1, sizeof(dp));
	cout << solve(names[0] + 1, 1) << endl;

	return 0;
}
