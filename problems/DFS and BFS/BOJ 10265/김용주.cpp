#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX_N 1001
using namespace std;
struct NODE{
	int next, cycle = 0, cycleCnt = 0, varCnt = 0;
};
int n, k, dp[MAX_N][MAX_N], ans;
bool visit[MAX_N], chk[MAX_N];
NODE node[MAX_N];
vector<pair<int, int> > list;
queue<int> q;

int dfs(int cur){
	visit[cur] = true;
	int nxt = node[cur].next;
	int cle = 0;
	//cycle이 이미 완성되었는지 확인
	if(!chk[nxt]){
		//dfs를 통해 cycle이 새로 생겼는지 확인
		if(visit[nxt]){
			int cnt = 1;
			node[cur].cycle = cur;
			while(nxt != cur){
				cnt++;
				node[nxt].cycle = cur;
				nxt = node[nxt].next;
			}
			node[cur].cycleCnt = cnt;
			node[cur].varCnt = -cnt;
			q.push(cur);
			cle = cur;
		}
		//cycle을 만들러 gogo
		else cle = dfs(nxt);
	}
	//이미 싸이클이 있다 => 가변인원 증가(가도 되고 안가도 되는 인원들)
	else
		cle = node[nxt].cycle;

	chk[cur] = true;
	node[cur].cycle = cle;
	node[cle].varCnt++;
	return cle;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &node[i].next);

	for(int i = 1; i <= n; i++)
		if(!chk[i]) dfs(i);

	//cycle의 크기가 버스에 탈 수 있는 인원보다 작은지 확인 크면 list에 넣음.
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(node[cur].cycleCnt > k) continue;
		list.push_back(make_pair(node[cur].cycleCnt, node[cur].varCnt));
	}

	list.push_back(make_pair(0, 0));
	sort(list.begin(), list.end());
	int lsize = list.size();

	memset(dp, -1, sizeof(dp));

	for(int i = 1; i < lsize; i++){
		int w = list[i].first;
		int v = list[i].second;
		dp[i][w] = v;
		for(int j = 1; j <= k; j++){
			//가장 작은 cycle의 수보다 버스좌석수가 많을 경우 가변인원까지 추가시킴.
			if(j > w){
				if(dp[i-1][j-w] >= 0)
					dp[i][j] = max(dp[i-1][j-w] + v , dp[i-1][j]);
				else
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
			else
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

	//dp에서 list size보다 1작은 곳에 있는 값들이 최댓값.
	for(int i = 1; i <= k; i++){
		if(dp[lsize-1][i] >= 0)
			ans = max(ans, i + dp[lsize-1][i]);
	}
	if (ans > k) printf("%d", k);
	else printf("%d", ans);

	return 0;
}