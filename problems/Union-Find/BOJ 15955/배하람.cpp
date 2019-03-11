#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

struct query{
    int from;
    int to;
    int hp;
    int idx;

    bool operator<(const query& rhs){
        return hp<rhs.hp;
    }
};

struct vertex{
    int x;
    int y;
    int idx;

    bool operator<(const vertex& rhs){
        return x<rhs.x;
    }
};

struct edge{
    int v1;
    int v2;
    int w;
};

struct Comparator {
    bool operator() (const edge& e1, const edge& e2) {
        return e1.w > e2.w;
    }
};

const int MAX_SIZE = 250005;
int n,q,cx,cy,a,b,hp;
int p[MAX_SIZE],r[MAX_SIZE],ans[MAX_SIZE];
query qu[MAX_SIZE];
vertex xv[MAX_SIZE],yv[MAX_SIZE];
priority_queue<edge,vector<edge>,Comparator> pq;

bool cmp(vertex a, vertex b) {
    return a.y==b.y?a.x<b.x:a.y<b.y;
}

int find(int v) {
    if(p[v]==v) return v;
    else return p[v]=find(p[v]);
}

void uni(int v1, int v2) {
    int p1 = find(v1);
    int p2 = find(v2);

    if(p1==p2) return;

    if(r[p1]<r[p2]) p[p1]=p2;
    else if(r[p1]>r[p2]) p[p2]=p1;
    else {
        p[p1]=p2;
        r[p2]++;
    }
}


int main(void)
{
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d%d",&cx,&cy);
        xv[i] = yv[i] = {cx,cy,i};
        p[i] = i;
        r[i] = 1;
    }

    for(int i=1; i<=q; i++){
        scanf("%d%d%d",&a,&b,&hp);
        qu[i] = {a,b,hp,i};
    }

    /*
        x좌표 및 y좌표 기준으로 정렬
        왜? 임의의 체크포인트에서 다른 체크포인트로 가는 최적의 방법이
        체크포인트와 수직/수평이 되는 방향으로 걷기 + 부스터로 체크포인트로 가기이기 때문에
        두 체크포인트 간의 가중치를 (x좌표 차이)와 (y좌표 차이)로 둘 수 있음
        O(NlgN)
    */ 

    sort(xv+1,xv+n+1);
    sort(yv+1,yv+n+1,cmp);

    /*
        x,y좌표 기준으로 정렬된 배열을 보면서
        인접한 체크포인트와 그 가중치를 "간선"으로 우선순위 큐에 삽입
        O(NlgN)
    */

    for(int i=2; i<=n; i++){
        int bxidx = xv[i-1].idx;
        int cxidx = xv[i].idx;

        int byidx = yv[i-1].idx;
        int cyidx = yv[i].idx;

        pq.push({bxidx,cxidx,xv[i].x-xv[i-1].x});
        pq.push({byidx,cyidx,yv[i].y-yv[i-1].y});
    }

    /*
        쿼리를 주어진 HP 기준으로 정렬
        왜? HP가 큰 것부터 하면 유니온-파인드로 합쳤을 때 
        HP가 작은 쿼리에 대해서 잘못된 결과가 도출될 수 있기 때문.
    */
    sort(qu+1,qu+q+1);

    for(int i=1; i<=q; i++){
        while(!pq.empty() && pq.top().w<=qu[i].hp) {
            edge e = pq.top(); pq.pop();
            uni(e.v1,e.v2);
        }
        ans[qu[i].idx] = find(qu[i].from)==find(qu[i].to) ? 1 : 0;
    }

    for(int i=1; i<=q; i++){
        ans[i] ? puts("YES") : puts("NO");
    }
    
    return 0;
}