#include <bits/stdc++.h>
#define M 10000
using namespace std;
int a[M+1],b[M+1],n,c[M+1];
int st[M+1],t,p[M+1];
void input(void){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
		b[c[i]]=i;
	}
}
int bisearch(int x){
	int s,e,md;
	for(s=1,e=t+1;s<e;st[md=(s+e)/2]>x ? e=md : s=md+1);
	return s;
}
void process(void){
	int i;
	for(i=1;i<=n;i++){
		int x=bisearch(b[a[i]]);
		if(x==t+1) st[++t]=b[a[i]];
		else st[x]=b[a[i]];
		p[b[a[i]]]=(x>0 ? st[x-1] : 0);
	}
}
void output(void){
	int x;
	vector<int> v;
	for(x=st[t];x;x=p[x]) v.push_back(c[x]);
	printf("%d\n",v.size());
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
}
int main(void){
	input();
	process();
	output();
	return 0;
}
