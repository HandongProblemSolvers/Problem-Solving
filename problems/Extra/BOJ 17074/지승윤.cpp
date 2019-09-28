#include <iostream>
using namespace std;
typedef long long ll;
ll a[100005], N, pos, cnt, ans;
int main(){
    cin>>N;
    a[0] = -10000000000;
    a[N+1] = 10000000000;
    for(int i = 1; i <= N; i++)
        cin>>a[i];
    for(int i = 1; i <= N+1; i++){
        if(a[i] < a[i-1]){
            cnt++;
            pos = i;
        }
    }
    if(cnt == 0) ans = N;
    else if(cnt > 1) ans = 0;
    else {
        if(a[pos-2] <= a[pos]) ans++;
        if(a[pos-1] <= a[pos+1]) ans++;
    }
    cout<<ans;
}
