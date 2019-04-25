#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double ans,D[2501][2501];
int	S,M,K,A[51];
int main(){
	cin>>M;
	for(int i = 1; i <= M; i++){
		cin>>A[i];
		S += A[i];
	}
	cin>>K;
	for(int i = 0; i <= 2500; i++){
		D[i][i] = 1;
		D[i][0] = 1;
	}
	for(int i = 2; i <= 2500; i++)
		for(int j = 1; j < i; j++)
			D[i][j] = D[i-1][j-1] + D[i-1][j];
	for(int i = 1; i <= M; i++)
		ans += D[A[i]][K];
	cout<<fixed;
	cout.precision(10);
	cout<<ans/D[S][K];
}
