#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll l,ans;
pair<ll,ll> a[100000];
map<ll,ll> u,d;
int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ll x = a[i].first;
        ll y = a[i].second;
        ll v1 = d[y] + abs(x-y) + l;
        ll v2 = u[x] + abs(x-y) + l;
        u[x] =  max(u[x],v1); 
        ans = max(ans, u[x]);
        d[y] = max(d[y],v2);  
        ans = max(ans, d[y]);
    }
    cout<<ans;
}