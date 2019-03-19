#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1;
string S, T, ans;
int control, idx, pos[M], fail[M];
void recursive_control(int s_i){
    if(s_i == S.length()) return;
    while(control > 0 && S[s_i] != T[control]) control = fail[control -1];
    if(S[s_i] == T[control]) control++;
    pos[ans.size()] = control;
    ans.push_back(S[s_i]);
    if(control == T.size()){
        for(int i = 0; i < T.size(); i++) ans.pop_back();
        control = pos[ans.size()-1];
    }
    recursive_control(++s_i);
}
int main(){
    cin>>S>>T;
    int p = 0;
    for(int i = 1; i < T.size(); i++){
        while(p>0 && T[i]!=T[p]) p = fail[p-1];
        if(T[i]==T[p]) p++;
        fail[i] = p;
    }
    recursive_control(0);
    cout<<ans;
}