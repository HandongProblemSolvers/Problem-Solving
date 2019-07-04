#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,t,k,a,b;
char board[101][101],temp[101][101];
vector<vector<int> > segTree;

int init1d(int row, int node2d, int s, int e, int node)
{
    if(s==e) return segTree[node2d][node] = (board[row][s]=='*'?1:0);
    return segTree[node2d][node] = 
        init1d(row,node2d,s,(s+e)/2,node*2)+init1d(row,node2d,(s+e)/2+1,e,node*2+1);
}

vector<int> init2d(int s, int e, int node)
{
    if(s==e) {
        init1d(s,node,1,m,1);
        return segTree[node];
    }
    vector<int> left = init2d(s,(s+e)/2,node*2);
    vector<int> right = init2d((s+e)/2+1,e,node*2+1);
    vector<int> ret;
    for(int i=0; i<left.size(); i++) ret.push_back(left[i]+right[i]);
    return segTree[node] = ret;
}

int query1d(int node2d, int node, int s, int e, int l, int r)
{
    if(e<l || s>r) return 0;
    if(l<=s && e<=r) return segTree[node2d][node];
    return query1d(node2d,node*2,s,(s+e)/2,l,r)+query1d(node2d,node*2+1,(s+e)/2+1,e,l,r);
}

int query2d(int node, int s, int e, int l, int r, int ll, int rr)
{
    if(e<l || s>r) return 0;
    if(l<=s && e<=r) return query1d(node,1,1,m,ll,rr);
    return query2d(node*2,s,(s+e)/2,l,r,ll,rr)+query2d(node*2+1,(s+e)/2+1,e,l,r,ll,rr);
}

void validation(int rs, int cs, int re, int ce)
{
    int curr=(rs+re)/2, curc=(cs+ce)/2;
    if(rs<1) rs = 1;
    if(cs<1) cs = 1;
    if(re>n) re = n;
    if(ce>m) ce = m;

    int life = query2d(1,1,n,rs,re,cs,ce);
    life -= (board[curr][curc]=='*'?1:0);

    if(board[curr][curc]=='*' && life<a) temp[curr][curc] = '.';
    else if(board[curr][curc]=='*' && life>b) temp[curr][curc] = '.';
    else if(board[curr][curc]=='.' && life>a && life<=b) temp[curr][curc] = '*';
}

int main(void)
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d",&k,&a,&b);
    for(int i=1; i<=n; i++) scanf("%s",&board[i][1]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp[i][j] = board[i][j];
        }
    }

    int rh = (int)ceil(log2(n));
    segTree.resize(1<<(rh+1));
    for(int i=1; i<segTree.size(); i++) {
        int ch = (int)ceil(log2(m));
        segTree[i].resize(1<<(ch+1));
    }

    while(t--) {
        init2d(1,n,1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                validation(i-k,j-k,i+k,j+k);
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                board[i][j] = temp[i][j];
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) printf("%c",board[i][j]);
        puts("");
    }

    return 0;
}