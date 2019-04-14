#include <bits/stdc++.h>
#define M 5005
using namespace std;
int fail[M], mx , p, N;
int main(){
    char T[M];
    cin>>T;
    N = strlen(T);
    char * S = T;
    for(int n = 0; n < N-1; n++){
        for(int i = 1; i <= N-n; i++){
            while(p && S[i] != S[p]) p = fail[p];
            if(S[i] == S[p]) p++;
            fail[i+1] = p;
            mx = max(p,mx);
        }
        p = 0;
        S++;
    }
    cout<<mx;
}
