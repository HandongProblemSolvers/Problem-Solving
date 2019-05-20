#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct co{int x,y,index;};
struct edge{co c1,c2; double cost; bool operator<(const edge& e) const { return cost<e.cost;}};
int p[501],r[501],vi[501][501];
vector<edge> e,mst;
vector<co> v;
int tc,n,s,xx,yy;

inline double dist(co c1, co c2){
    return sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
}

int find(int v){
    if(v==p[v]) return v;
    else return p[v] = find(p[v]);
}

void uni(int v1, int v2){
    int p1 = find(v1), p2 = find(v2);
    if(p1!=p2){
        if(r[p1]<r[p2]) p[p1] = p2;
        else if(r[p1]>r[p2]) p[p2] = p1;
        else {
            p[p1] = p2;
            r[p2]++;
        }
    }
}

int main(void)
{
    scanf("%d",&tc);

    while(tc--){
        scanf("%d%d",&n,&s);
        for(int i=0; i<s; i++){
            scanf("%d%d",&xx,&yy);
            v.push_back({xx,yy,i});
            p[i] = i;
            r[i] = 1;
        }

        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                if(i==j || vi[i][j]) continue;
                vi[i][j] = vi[j][i] = 1;
                e.push_back({v[i],v[j],dist(v[i],v[j])});
            }
        }

        sort(e.begin(),e.end());

        for(edge _e : e){
            int v1 = _e.c1.index, v2 = _e.c2.index;
            if(find(v1)!=find(v2)){
                mst.push_back(_e);
                uni(v1,v2);
            }
        }

        for(int i=mst.size()-1; i>=0; i--){
            if(n-1){
                n--;
                continue;
            }
            printf("%.2lf\n",mst[i].cost);
            break;
        }
        
        e.clear();
        mst.clear();
        v.clear();
        memset(vi,0,sizeof(vi));
    }
    return 0;
}
