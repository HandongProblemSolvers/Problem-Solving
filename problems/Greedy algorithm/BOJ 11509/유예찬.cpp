// baekjoon 11509 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int N, x, ret, a[1000001];
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &x);
		if (a[x]) a[x]--;
		else ret++;
		a[x-1]++;
	}
	printf("%d\n",ret);
	return 0;
}