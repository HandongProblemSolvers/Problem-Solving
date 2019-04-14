// baekjoon 2873 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_D=4;
const int dir[4][2] = {{0,1}, {1,0}, {0, 1}, {-1, 0}};
const char dir_c[6] = "RDRU\0";
int R, C, x, ret=1e9, sx, sy, cx, cy, nx, ny;

int main() {
	scanf("%d%d", &R, &C);
	if (R % 2) {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C-1; j++) {
				if (i%2) printf("L");
				else printf("R");
			}
			if (i!=R-1) printf("D");
		}
	} else if (C % 2) {
		for (int i=0; i<C; i++) {
			for (int j=0; j<R-1; j++) {
				if (i%2) printf("U");
				else printf("D");
			}
			if (i!=C-1) printf("R");
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
						printf("%c", dir_c[d]);
						d = (d+1)%MAX_D;
						cx = nx, cy = ny;
					}
				}
				if (i != R/2-1) printf("D");
			} else if (i < sx/2) {
				for (int j=0; j<C-1; j++) printf("R");
				printf("D");
				for (int j=0; j<C-1; j++) printf("L");
				printf("D");
			} else {
				for (int j=0; j<C-1; j++) printf("L");
				printf("D");
				for (int j=0; j<C-1; j++) printf("R");
				if (i != R/2-1) printf("D");
			}
		}
	}
	return 0;
}