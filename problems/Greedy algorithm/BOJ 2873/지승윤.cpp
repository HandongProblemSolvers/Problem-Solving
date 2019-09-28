#include <bits/stdc++.h>
using namespace std;
int R, C, t, mn=1001, x, y;
int main(){
	cin>>R>>C;
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++){
			cin>>t;
			if((i+j)%2 && mn > t){
				mn = t;
				x = i;
				y = j;
			}
		}
	if(R%2){
		for(int i = 1; i <= R/2; i++){
			for(int j = 1; j < C; j++)	cout<<"R";	cout<<"D";
			for(int j = 1; j < C; j++)	cout<<"L";	cout<<"D";
		}
		for(int j = 1; j < C; j++)	cout<<"R";
	}
	else if(C%2){
		for(int i = 1; i <= C/2; i++){
			for(int j = 1; j < R; j++)	cout<<"D";	cout<<"R";
			for(int j = 1; j < R; j++)	cout<<"U";	cout<<"R";
		}
		for(int j = 1; j < R; j++)	cout<<"D";
	}
	else{
		int i, j;
		for(i = 1; i < (x+1)/2; i++){
			for(int j = 1; j < C; j++) cout<<"R"; cout<<"D";
			for(int j = 1; j < C; j++) cout<<"L"; cout<<"D";
		}
		for(j = 1; j < (y+1)/2; j++)
			cout<<"DRUR";
		if(x%2) cout<<"DR";
		else cout<<"RD";
		for(j = j+1; j <= C/2; j++)
			cout<<"RURD";
		for(i = i+1; i <= R/2; i++){
			cout<<"D";	for(int j = 1; j < C; j++) cout<<"L";
			cout<<"D";	for(int j = 1; j < C; j++) cout<<"R";
		}
	}
}
