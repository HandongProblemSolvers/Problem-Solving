// baekjoon 17140 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int R, C, K;
int board[MAX_N][MAX_N];
pair<int,int> value[MAX_N];
int cur_R=3, cur_C=3;

void cal_R()
{
	int next_C = cur_C;
	for (int i=1; i<=cur_R; i++)
	{
		memset(value, 0, sizeof(value));
		for (int j=1; j<MAX_N; j++)
			value[j].second = j;

		for (int j=1; j<=cur_C; j++)
			value[board[i][j]].first++;

		sort(value+1, value+MAX_N);

		int idx=1;
		for (int j=1; j<MAX_N; j++)
		{
			if (!value[j].first) continue;
			if (idx > 100) break;
			board[i][idx++]=value[j].second;
			if (idx > 100) break;
			board[i][idx++]=value[j].first;
		}
		for (int j=idx; j<MAX_N; j++)
			board[i][j]=0;

		next_C = max(next_C, idx-1);
	}
	cur_C = max(cur_C, next_C);
}

void cal_C()
{
	int next_R = cur_R;
	for (int i=1; i<=cur_C; i++)
	{
		memset(value, 0, sizeof(value));
		for (int j=1; j<MAX_N; j++) 
			value[j].second=j;

		for (int j=1; j<=cur_R; j++)
			value[board[j][i]].first++;
		
		sort(value+1, value+MAX_N);

		int idx=1;
		for (int j=1; j<MAX_N; j++)
		{
			if (!value[j].first) continue;
			if (idx > 100) break;
			board[idx++][i]=value[j].second;
			if (idx > 100) break;
			board[idx++][i]=value[j].first;
		}
		for (int j=idx; j<MAX_N; j++)
			board[j][i]=0;

		next_R = max(next_R, idx-1);
	}
	cur_R = max(cur_R, next_R);
}

int main()
{
	scanf("%d%d%d", &R, &C, &K);
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			scanf("%d", &board[i][j]);

	int t=0;

	while (board[R][C] != K && t <= 100)
	{
		if (cur_R >= cur_C) cal_R();
		else cal_C();
		t++;
	}
	printf("%d\n", t>100 ? -1 : t);
	return 0;
}