//for GOD 
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int N, a, tmp;
ll arr[500001];
map<int, int> m;

ll sum(ll tree[], int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(ll tree[], int i, int diff) {
    while (i <= N) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>N;
	
	for(int i = 1; i <= N; i++){
		cin>>tmp;
		m[tmp] = i;
	}
	
	for(int i = 1; i <= N; i++){
		cin>>tmp;
		update(arr,m[tmp],1);
		a += (sum(arr,N) - sum(arr,m[tmp]));
	}
	
	cout<<a<<"\n";
}
