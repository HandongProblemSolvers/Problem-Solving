#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int N,M,A,B,C;
vector<int> T,ST;
vector<pair<int,int>> Q;

int init(int s, int e, int no) {
    if(s==e) return ST[no] = T[s];
    else return ST[no] = min(init(s,(s+e)/2,no*2),init((s+e)/2+1,e,no*2+1));
}

int query(int s, int e, int l, int r, int no) {
    if(l>e || r<s) return INF;
    if(l<=s && r>=e) return ST[no];
    return min(query(s,(s+e)/2,l,r,no*2),query((s+e)/2+1,e,l,r,no*2+1));
}

int main(void)
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++) {
        scanf("%d",&C);
        T.push_back(C);
    }
    for(int i=0; i<M; i++) {
        scanf("%d%d",&A,&B);
        Q.push_back({A,B});
    }

    ST.resize(4*N,INF);
    init(0,N-1,1);

    for(int i=0; i<Q.size(); i++) 
        printf("%d\n",query(0,N-1,Q[i].first-1,Q[i].second-1,1));

    return 0;
}