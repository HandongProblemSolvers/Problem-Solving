#include <bits/stdc++.h>
using namespace std;
int m[101][101], n, x, y, d, g, tx, ty, ans;
vector<int> v;
int main(){
	cin>>n;
	while(n--){
		cin>>tx>>ty>>d>>g;
		x = tx;	y = ty;
		v.clear();
		v.push_back(d);
		for(int i = 0; i < g; i++)
			for(int j = v.size()-1; j >= 0; j--)
				v.push_back((v[j]+1)%4);
		for(int i = 0; i < v.size(); i++){
			m[x][y]=1;
			if(v[i] == 0)	m[++x][y]=1;
			if(v[i] == 1)	m[x][--y]=1;
			if(v[i] == 2)	m[--x][y]=1;
			if(v[i] == 3)	m[x][++y]=1;
		}
	}	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			if(m[i][j]&&m[i+1][j]&&m[i][j+1]&&m[i+1][j+1]) ans++;
	cout<<ans<<endl;
}
