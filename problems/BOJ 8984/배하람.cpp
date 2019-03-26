#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MAX_SIZE = 100005;

pii stick[MAX_SIZE];
int top[MAX_SIZE],down[MAX_SIZE];
ll tdp[MAX_SIZE],ddp[MAX_SIZE];
vector<int> rtop,rdown;
int N,L;

bool findValue(int left, int right, int target, vector<int>& vec) {
    while(left<=right) {
        int m = (left+right)/2;
        if(target<vec[m]) right = m-1;
        else if(target>vec[m]) left = m+1;
        else return true;
    }
    return false;
}

int main(void)
{
    scanf("%d%d",&N,&L);

    for(int i=1; i<=N; i++) {
        scanf("%d%d",&stick[i].first,&stick[i].second);
        top[i] = stick[i].first;
        down[i] = stick[i].second;
    }

    sort(stick+1,stick+N+1);
    sort(top+1,top+N+1);
    sort(down+1,down+N+1);

    rtop.push_back(top[1]);
    rdown.push_back(down[1]);
    for(int i=2; i<=N; i++) {
        if(!findValue(0,rtop.size()-1,top[i],rtop)) {
            rtop.push_back(top[i]);
        } 
        if(!findValue(0,rdown.size()-1,down[i],rdown)) {
            rdown.push_back(down[i]);
        }
    }

    ll ans = 0LL;
    for(int i=1; i<=N; i++) {
        int tidx = lower_bound(rtop.begin(),rtop.end(),stick[i].first) - rtop.begin();
        int didx = lower_bound(rdown.begin(),rdown.end(),stick[i].second) - rdown.begin();

        ll len = abs(rtop[tidx]-rdown[didx]) + L;
        ll ttemp = tdp[tidx];
        ll dtemp = ddp[didx];
        tdp[tidx] = max(ttemp, dtemp+len);
        ddp[didx] = max(dtemp, ttemp+len);
        ans = max(ans,max(tdp[tidx],ddp[didx]));
    }

    printf("%lld",ans);

    return 0;
}