#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[301], DP[301][3], n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++){
		DP[i][0] = max(DP[i-1][1],DP[i-1][2]);
		DP[i][1] = DP[i-1][0] + a[i];
		DP[i][2] = DP[i-1][1] + a[i];
	}
	cout<<max(DP[n][1], DP[n][2]);
}
