#include <bits/stdc++.h>
#define M 10007
using namespace std;
typedef long long ll;
ll a[M], D[2][M/2], N, step = 1, mod = 1e9+7;
int main(){
    cin>>N;
    for(int i = 1; i <= N; ++i)
        cin>>a[i];
    D[1][0] = (a[1]<=0)?1:0;
    while(++step <= N) {
        int t = step%2;
        memset(D[t],0,sizeof(D[t]));
        if(a[step]<0){
            D[t][0] = (D[t^1][1] + D[t^1][0])%mod;
            for(int i = 1; i <= N/2; ++i) D[t][i] = (D[t^1][i+1]+D[t^1][i]+D[t^1][i-1])%mod;
        }  
        else if(!a[step]) D[t][0] = (D[t^1][0]+D[t^1][1])%mod;
        else D[t][a[step]] = (D[t^1][a[step]+1]+D[t^1][a[step]]+D[t^1][a[step]-1])%mod;
    }
    cout<<D[N%2][0];    
}