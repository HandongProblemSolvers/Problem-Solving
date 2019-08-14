//BOJ1234 크리스마스 트리
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, R, G, B;
ll dp[11][101][101][101];
ll ft[11];

ll comb(int n, int k){
	ll result = ft[n];
	for(int i = 0; i < k; i++)
		result /= ft[n/k];

	return result;
}

ll cmt(int n, int r, int g, int b){
	if(r < 0 || g < 0 || b < 0) return 0;
	if(n == 0) return 1;

	ll &ret = dp[n][r][g][b];
	if(ret) return ret;

	ret += cmt(n-1, r-n, g, b);	
	ret += cmt(n-1, r, g-n, b);	
	ret += cmt(n-1, r, g, b-n);

	if(n % 2 == 0){
		ret += comb(n, 2) * cmt(n-1, r, g-n/2, b-n/2);
		ret += comb(n, 2) * cmt(n-1, r-n/2, g, b-n/2);
		ret += comb(n, 2) * cmt(n-1, r-n/2, g-n/2, b);
	}

	if(n % 3 == 0){
		ret += comb(n, 3) * cmt(n-1, r-n/3, g-n/3, b-n/3);
	}

	return ret;
}


int main(){
	scanf("%d %d %d %d", &N, &R, &G, &B);
	ft[0] = 1;
	for(int i = 1; i <= N; i++) {
		ft[i] = ft[i-1] * i;
	}
	printf("%lld", cmt(N, R, G, B));

	return 0;
}