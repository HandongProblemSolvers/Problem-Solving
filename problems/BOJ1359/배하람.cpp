#include <cstdio>
#include <vector>
using namespace std;

const int SIZE = 100001;
int n,m,o,ss,tt;
int segTree[4*SIZE];
bool arr[SIZE],lazy[4*SIZE];

void propagate(int s, int e, int node)
{
    if(lazy[node]){
        segTree[node] = (e-s+1) - segTree[node];
        if(s!=e) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = false;
    }
}

void update(int l, int r, int node, int s, int e)
{
    propagate(s,e,node);
    if(r<s || l>e) return;
    if(l<=s && e<=r) {
        segTree[node] = (e-s+1) - segTree[node];
        if(s!=e) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return;
    }
    int mid = (s+e)/2;
    update(l,r,node*2,s,mid);
    update(l,r,node*2+1,mid+1,e);
    segTree[node] = segTree[node*2] + segTree[node*2+1];
}

int query(int l, int r, int node, int s, int e)
{
    propagate(s,e,node);
    if(r<s || l>e) return 0;
    if(l<=s && e<=r) return segTree[node];
    int mid = (s+e)/2;
    return query(l,r,node*2,s,mid)+query(l,r,node*2+1,mid+1,e);
}

int main(void)
{
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&o,&ss,&tt);
        if(o==0) update(ss-1,tt-1,1,0,n-1);
        else printf("%d\n",query(ss-1,tt-1,1,0,n-1));
    }
    return 0;
}