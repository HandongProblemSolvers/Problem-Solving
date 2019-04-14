#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
int ans;

int main(void)
{
    cin >> s;

    for(int i=0; i<s.size(); i++){
        vector<int> f(s.size(),0);
        int begin=i+1,match=0;
        while(begin+match<s.size() && match+i<s.size()) {
            if(s[begin+match]==s[match+i]){
                match++;
                f[begin+match-1]=match;
                ans=max(ans,match);
            } else{
                if(match==0) begin++;
                else{
                    begin+=(match-f[match+i-1]);
                    match=f[match+i-1];
                }
            }
        }
    }

    cout << ans;
    return 0;
}