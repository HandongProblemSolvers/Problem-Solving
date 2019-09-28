// baekjoon 14891 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int K, gpos[5]; // 12시 방향 위치
char gear[5][9]; // gear[톱니바퀴 번호(0~3)][기어 시계방향(0~7)]

void turnGear(int here, int d) {
	gpos[here] = (8 + gpos[here] - d) % 8;
}

inline int getLeft(int here) { return (gpos[here]+2)%8; }
inline int getRight(int here) { return (gpos[here]+6)%8; }

void changeGear(int here, int pv, int d) {
	if (here < 1 || here > 4) return; // bound condition

	bool left=false, right=false;
	if (pv != here-1 && gear[here-1][getLeft(here-1)] != gear[here][getRight(here)]) 
		left=true;

	if (pv != here+1 && gear[here+1][getRight(here+1)] != gear[here][getLeft(here)]) right=true;

	turnGear(here, d);
	if (left) changeGear(here-1, here, (-1)*d);
	if (right) changeGear(here+1, here, (-1)*d);
}

int main() {
	for (int g=1; g<=4; g++)
		scanf("%s", gear[g]);

	scanf("%d", &K);
	while (K--) {
		int N, dir;
		scanf("%d%d", &N, &dir);
		changeGear(N, -1, dir);
	}

	int ret = 0;
	for (int i=1; i<=4; i++)
		ret += ((gear[i][gpos[i]]-'0')<<(i-1));
	printf("%d\n", ret);
	return 0;
}