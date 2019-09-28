// baekjoon 2873 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_D=4;
const int dir[4][2] = {{0,1}, {1,0}, {0, 1}, {-1, 0}};
const char dir_c[6] = "RDRU\0";
int R, C, x, ret=1e9, sx, sy, cx, cy, nx, ny, pos;
char ans[1000001];

int main() {
	scanf("%d%d", &R, &C);
	if (R % 2) {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C-1; j++) {
				if (i%2) ans[pos++] = 'L';
				else ans[pos++] = 'R';
			}
			if (i!=R-1) ans[pos++] = 'D';
		}
	} else if (C % 2) {
		for (int i=0; i<C; i++) {
			for (int j=0; j<R-1; j++) {
				if (i%2) ans[pos++] = 'U';
				else ans[pos++] = 'D';
			}
			if (i!=C-1) ans[pos++] = 'R';
		}
	} else {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				scanf("%d", &x);
				if ((i+j)%2 && x < ret) ret = x, sx=i, sy=j;
			}
		}
		for (int i=0; i<R/2; i++) {
			if (i == sx/2) {
				cx = i*2, cy = 0;
				int d=1;
				while (cx != i*2+1 || cy != C-1) {
					nx = dir[d][0] + cx, ny = dir[d][1] + cy;
					if (nx == sx && ny == sy) d = (d+3)%MAX_D;
					else {
						ans[pos++] = dir_c[d];
						d = (d+1)%MAX_D;
						cx = nx, cy = ny;
					}
				}
				if (i != R/2-1) ans[pos++] = 'D';
			} else if (i < sx/2) {
				for (int j=0; j<C-1; j++) ans[pos++] = 'R';
				ans[pos++] = 'D';
				for (int j=0; j<C-1; j++) ans[pos++] = 'L';
				ans[pos++] = 'D';
			} else {
				for (int j=0; j<C-1; j++) ans[pos++] = 'L';
				ans[pos++] = 'D';
				for (int j=0; j<C-1; j++) ans[pos++] = 'R';
				if (i != R/2-1) ans[pos++] = 'D';
			}
		}
	}
	ans[pos]='\0';
	puts(ans);
	return 0;
}