// baekjoon 17143 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_M=10001;
const int MAX_R=101;
const int dir[4][2] = {{0, -1},{0, 1},{1, 0},{-1, 0}}; // 위 아래, 오른쪽, 왼쪽 // (x, y) (c, r)

int R, C, M;
bool life[MAX_M];

struct Block
{
	int size, idx;
	Block():size(0), idx(0){}
	Block(int size, int idx):size(size), idx(idx){}
};
Block board[MAX_R][MAX_R]; // {Shark Size, Shark idx}

inline int encode(int x, int key, int d) { return (d < 0) ? key*2-x : x; }
inline int decode(int x, int key) { x %= key*2; return (x > key) ? key*2-x : x; }

struct Shark
{
	int r, c, s, d, z;
	Shark():r(0), c(0), s(0), d(0), z(0){}
	Shark(int r, int c, int s, int d, int z):r(r),c(c),s(s),d(d),z(z){}

	void Move(int t, int cur)
	{
		// dead shark
		if (!life[cur]) return;

		int cur_r = encode(r, R-1, dir[d][1]), cur_c = encode(c, C-1, dir[d][0]);
		cur_r = decode(abs(dir[d][1])*t*s + cur_r, R-1);
		cur_c = decode(abs(dir[d][0])*t*s + cur_c, C-1);
		if (board[cur_c][cur_r].size)
		{
			if (board[cur_c][cur_r].size > z) life[cur] = false;
			else life[board[cur_c][cur_r].idx] = false, board[cur_c][cur_r] = Block(z, cur);
		}
		else
		{
			board[cur_c][cur_r] = Block(z, cur);
		}
	}
};
Shark shark[MAX_M];

int main()
{
	fill(life, life+MAX_M, true);

	scanf("%d%d%d", &R, &C, &M);
	int r, c, s, d, z;
	for (int i=0; i<M; i++) {
		scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
		shark[i] = Shark(r-1, c-1, s, d-1, z);
	}

	int ret = 0;
	for (int i=0; i<C; i++)
	{
		memset(board, 0, sizeof(board));
		for (int j=0; j<M; j++) shark[j].Move(i, j);
		for (int j=0; j<R; j++)
		{
			if (board[i][j].size) {
				ret += board[i][j].size;
				life[board[i][j].idx]=false;
				break;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}