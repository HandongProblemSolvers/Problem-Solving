// baekjoon 4343 yechan 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define SQ(x) ((x)*(x))
const int MAX_P=500;
const int MAX_V=250000;
// size : ((N-1)*N)/2;
int T, S, P, vSize, root[MAX_P];
pair<int, int> pos[MAX_P];
pair<double, pair<int, int> > v[MAX_V];

inline double dist(pair<int,int> &A, pair<int,int> &B) {
	return sqrt(double(SQ(A.first-B.first)+SQ(A.second-B.second)));
}

int find(int x) {
	if (root[x]==-1) return x;
	return root[x] = find(root[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(root, -1, sizeof(root));
		memset(v, 0, sizeof(v));
		scanf("%d%d", &S, &P);
		vSize = (P*(P-1))/2;
		for (int i=0; i<P; i++)
			scanf("%d%d", &pos[i].first, &pos[i].second);
		for (int i=0, z=0; i<P; i++) {
			for (int j=i+1; j<P; j++, z++) {
				v[z].first = dist(pos[i], pos[j]);
				v[z].second.first = i;
				v[z].second.second = j;
			}
		}

		double ret = 0;
		sort(v, v+vSize);
		for (int i=0; i<vSize; i++) {
			if (P-S == 0) break;
			int a = v[i].second.first;
			int b = v[i].second.second;
			if (!merge(a, b)) continue;
			P--;
			ret = v[i].first;
		}
		printf("%.2f\n", ret);
	}
	return 0;
}