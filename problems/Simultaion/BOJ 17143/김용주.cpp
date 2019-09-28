//BOJ 17143
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_R 101
#define MAX_M 10201
struct shark{
	int r, c, s, d, z;
};

int R, C, M, board[MAX_R][MAX_R], ans;
shark shk[MAX_M];
bool life[MAX_M];

void move(){
	for(int i = 1; i <= M; i++){
		if(life[i]) continue;
		int r = shk[i].r;
		int c = shk[i].c;
		int s = shk[i].s;
		int d = shk[i].d;
		int z = shk[i].z;

		if(d == 1 || d == 2){
			while(s--){
				if(d == 1 && r == 1 || d == 2 && r == R){
					d = (d%2) + 1;
				}
				if(d == 1) r--;
				else r++;
			}
		}

		else{
			while(s--){
				if(d == 3 && c == C || d == 4 && c == 1)
					d = (d%2) + 3;
				if(d == 3) c++;
				else c--;
			}
		}
		
		shk[i].r = r;
		shk[i].c = c;
		shk[i].d = d;
		int loc = board[r][c];
		if(loc){
			if(shk[loc].z > z) {
				life[i] = true;
			}

			else{
				life[loc] = true;
				board[r][c] = i;
			}
		}
		else
			board[r][c] = i;
	}
}

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int i = 1; i <= M; i++){
		scanf("%d %d %d %d %d", &shk[i].r, &shk[i].c, &shk[i].s, &shk[i].d, &shk[i].z);
		board[shk[i].r][shk[i].c] = i;
	}

	for(int i = 1; i <= C; i++){
		for(int j = 1; j <= R; j++){
			int loc = board[j][i];
			if(loc) {
				ans += shk[loc].z;
				life[loc] = true;
				// printf("%d %d %d %d %d %d %d\n",j, i, shk[loc].r, shk[loc].c, shk[loc].s, shk[loc].d, shk[loc]. z);
				break;
			}
		}
		memset(board, 0, sizeof(board));
		move();
	}
	printf("%d\n", ans);

	return 0;
}