#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=11;

int X, Y, N, M;
pair<int, int> cur;
pair<int, int> Nlist[MAX_N], Mlist[MAX_N];

int main(void) {
	scanf("%02d:%02d", &cur.first, &cur.second);
	scanf("%d%d", &X, &Y);
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%02d:%02d", &Nlist[i].first, &Nlist[i].second);
	for (int i=0; i<M; i++)
		scanf("%02d:%02d", &Mlist[i].first, &Mlist[i].second);

	for (int i=0; i<N; i++) {
		if (cur.first < Nlist[i].first || (cur.first == Nlist[i].first && cur.second <= Nlist[i].second)) {
			cur.first = Nlist[i].first + (Nlist[i].second + X)/60;
			cur.second = (Nlist[i].second + X)%60;
			break;
		}
	}

	for (int i=0; i<M; i++) {
		if (cur.first < Mlist[i].first || (cur.first == Mlist[i].first && cur.second <= Mlist[i].second)){
			cur.first = Mlist[i].first + (Mlist[i].second + Y)/60;
			cur.second = (Mlist[i].second + Y)%60;
			break;
		}
	}
	printf("%02d:%02d\n", cur.first, cur.second);
    return 0;
}