#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int A[500001],B[10000001];
int N,T;

int query(vector<int>& tree, int node, int s, int e, int l, int r)
{
    if(l>e || r<s) return 0;
    if(s>=l && e<=r) return tree[node];
    return query(tree,node*2,s,(s+e)/2,l,r)+query(tree,node*2+1,(s+e)/2+1,e,l,r);
}

void update(vector<int>& tree, int node, int index, int s, int e)
{
    if(index<s || index>e) return;
    tree[node] += 1;
    if(s==e) return;
    update(tree,node*2,index,s,(s+e)/2);
    update(tree,node*2+1,index,(s+e)/2+1,e);
}

int main(void)
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&A[i]);
    }
    for(int i=1; i<=N; i++) {
        scanf("%d",&T);
        B[T] = i;
    }

    vector<int> tree(4*N);

    long long ans = 0LL;
    for(int i=1; i<=N; i++){
        int bidx = B[A[i]];
        ans += (long long)query(tree,1,1,N,bidx+1,N);
        update(tree,1,bidx,1,N);
    }

    printf("%lld\n",ans);

    return 0;
}