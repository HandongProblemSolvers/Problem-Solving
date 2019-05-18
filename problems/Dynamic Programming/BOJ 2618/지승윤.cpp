#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int x[1001], y[1001];
int dp[1001][1001];
bool visit[1001][1001];
int n, w;

int solve(int n1, int n2){
	int now = max(n1, n2);
	if (now == w)return 0;
	if (dp[n1][n2] != -1)return dp[n1][n2];
	int p1 = solve(now + 1, n2);
	int p2 = solve(n1, now + 1);
	if (!n1)
		p1 += x[now] + y[now];
	else
		p1 = p1 + abs(x[now] - x[n1 - 1]) + abs(y[now] - y[n1 - 1]);
	if (!n2)
		p2 += n + n - x[now] - y[now];
	else
		p2 = p2 + abs(x[now] - x[n2 - 1]) + abs(y[now] - y[n2 - 1]);
	visit[n1][n2] = p1 > p2;
	return dp[n1][n2] = min(p1, p2);
}

void print(int n1, int n2){
	int now = max(n1, n2);
	if (now == w)return;
	cout<<visit[n1][n2] + 1<<'\n';
	if (visit[n1][n2])print(n1, now + 1);
	else print(now + 1, n2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>w;
	for (int i = 0; i < w; i++){
		cin>>x[i]>>y[i];
		x[i]--;
		y[i]--;
	}
	memset(dp, -1, sizeof(dp));
	--n;
	int result = solve(0,0);
	cout<<result<<'\n';
	print(0,0);
	return 0;
}
