//BOJ7578 공장
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
const int SIZE = 1 << 19;
int N, A[MAX_N], B[MAX_N], arr[2 * SIZE];
long long ans;

void update(int i, int val) {
	i += SIZE;
	arr[i] = val;
	while (i > 1) {
		i /= 2;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}

int segSum(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return segSum(nodeL, mid, nodeNum * 2, L, R) + segSum(mid + 1, nodeR, nodeNum * 2 + 1, L, R);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    for(int i = 0; i < N; i++){
        int b;
        scanf("%d", &b);
        B[b] = i;
    }

    for(int i = 0; i < N; i++){
        ans += segSum(0, SIZE - 1, 1, B[A[i]], MAX_N);
        update(B[A[i]], 1);
    }
    printf("%lld", ans);

    return 0;
}