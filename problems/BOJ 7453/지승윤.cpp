#include <iostream>
#include <algorithm>
#define M 2147483647
using namespace std;
int map[5000][10], b1[20000000], b2[20000000];
long long cnt;
int main(){
	long long n, i,j,s,e;
	cin>>n;
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= 4; j++) cin>>map[i][j];
	cnt = 0;
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= n; j++){
			cnt++; 
			b1[cnt] = map[i][1] + map[j][2];
			b2[cnt] = map[i][3] + map[j][4];
		}
	sort(b1 + 1, b1 + n * n + 1); sort(b2 + 1, b2 + n * n + 1); 
    b1[0] = M; b2[0] = M;
	b1[n*n+1] = M; b2[n*n+1] = M;
	s = 1; e = n * n;
	cnt = 0;
	while (1){
		if (s > n*n || e == 0) break;
		if (b1[s] + b2[e] > 0) e--;
		else if (b1[s] + b2[e] < 0) s++;
		else{
			long long int cnt1 = 0, cnt2 = 0;
			int t = b1[s];
			while (b1[s] == t) { s++; cnt1++; }
			t = b2[e];
			while (b2[e] == t) { e--; cnt2++; }
			cnt += (cnt1*cnt2);
		}
	}
	cout<<cnt;
	return 0;
}
