// baekjoon 1014_2 network flow yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> P;

const int MAX_N=11;
const int dir[6][2] = {{0,-1},{1,-1},{0,1},{1,1},{-1,-1},{-1,1}};

int T, N, M, noSeat;
P aMatch[MAX_N][MAX_N], bMatch[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];
vector<P> adj[MAX_N][MAX_N];

bool dfs(P here)
{
	int x = here.first, y = here.second;
	if (visited[x][y]) return false;

	visited[x][y] = true;
	for (auto& p : adj[x][y]) {
		int nx = p.first, ny = p.second;
		if (bMatch[nx][ny] == P(-1, -1) || dfs(bMatch[nx][ny])) {
			aMatch[x][y] = P(nx, ny);
			bMatch[nx][ny] = P(x, y);
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		noSeat = 0;

		scanf("%d%d", &N, &M);
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				adj[i][j].clear();

		for (int i=0; i<N; i++)
		{
			scanf("%s", board[i]);
			for (int j=0; j<M; j++)
				if (board[i][j] == 'x') noSeat++;
		}

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j+=2)
			{
				if (board[i][j]=='x') continue;
				for (int d=0; d<6; d++)
				{
					int nx = i + dir[d][0], ny = j + dir[d][1];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (board[nx][ny] == 'x') continue;
					adj[i][j].push_back(P(nx, ny));
				}
			}
		}

		int matched=0;
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				aMatch[i][j] = P(-1, -1), bMatch[i][j] = P(-1, -1);

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j+=2)
			{
				if (board[i][j] == 'x') continue;
				memset(visited, 0, sizeof(visited));
				if (dfs(P(i, j))) matched++;
			}
		}
		printf("%d\n", N*M - noSeat - matched);
	}

	return 0;
}