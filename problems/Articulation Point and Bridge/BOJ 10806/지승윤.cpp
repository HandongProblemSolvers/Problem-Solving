#include<bits/stdc++.h>
using namespace std;
int n, m, chk[100001], cut_edge, cut_chk, num = 1;
vector<pair<int, int> > isCut;
vector<int> adj[100001], ans;
set<pair<int, int> > yesCut;
set<pair<int, int> > noCut;
//Find CutEdge
int dfs(int here, int parent){
	chk[here] = num++;
	int ret = chk[here];
	for(int i = 0; i < adj[here].size(); i++){
		int next = adj[here][i];
		if(next == parent) continue;
		if(chk[next]){
			ret = min(ret,chk[next]);
			continue;
		}
		int prev = dfs(next,here);
		if(prev > chk[here] && noCut.find({min(next,here), max(next,here)}) == noCut.end())
			isCut.push_back({min(next,here), max(next,here)});
		ret = min(ret,prev);
	}
	return ret;
}
//Find End of CutEdge
void cut_dfs(int v, int ban){
    chk[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        if(chk[adj[v][i]] == -1 && adj[v][i] != ban){
            cut_edge++;
            cut_chk--;
            continue;
        }
        if(cut_edge > 1) break;
        if(!chk[adj[v][i]]){
            if(ban==v) cut_chk = 1;
            cut_dfs(adj[v][i],ban);
            if(ban==v&&cut_chk<1)
                chk[adj[v][i]] = -1;
        }      
    }
    chk[v] = false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int x,y;
	for(int i = 0; i < m; i++){
		cin>>x>>y;
        if(yesCut.find({min(x,y), max(x,y)})==yesCut.end()) 
            yesCut.insert({min(x,y), max(x,y)});
        else{
            noCut.insert({min(x,y), max(x,y)});
            continue;
        } 
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		if(!chk[i]) dfs(i,0);
    memset(chk,false,sizeof(chk));
    for(int i = 0; i < isCut.size(); i++){
        chk[isCut[i].first] = -1;
        chk[isCut[i].second] = -1;
    }
	for(int i = 0; i < isCut.size(); i++){
        cut_edge = 0;
        cut_dfs(isCut[i].first, isCut[i].first);
        chk[isCut[i].first] = -1;
        if(cut_edge == 1) ans.push_back(isCut[i].first);
        cut_edge = 0;
        cut_dfs(isCut[i].second, isCut[i].second);
        chk[isCut[i].second] = -1;
        if(cut_edge == 1) ans.push_back(isCut[i].second);
    }
   if(ans.size()%2) ans.push_back(ans.front());
   cout<<ans.size()/2<<endl;
   for(int i = 0; i < ans.size(); i += 2){
       cout<<ans[i]<<" "<<ans[i+1]<<"\n";
   }
}