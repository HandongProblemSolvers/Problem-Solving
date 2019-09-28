#include <cstdio>
#include <queue>
using namespace std;

int min_route = 99898989;
int N, M, K;
int q, w, e, r;
int dx[4] = {0 , 0 , 1, -1};
int dy[4] = {1 , -1 , 0, 0};
struct cnt{
    int cost;
    int time;
};
cnt map[101][101];
int visit[101][101];

int dfs(int x, int y, int tmm, int cstt){
    
    int tx = x;
    int ty = y;
    int tm = tmm;
    int cst = cstt;

    if(x==N && y==N){
        if(tmm < min_route) min_route = tmm;
        return min_route;
    }

    if(cstt > M) return -1;

    for(int i=0; i< 4 ; i++){
        int cx = tx + dx[i];
        int cy = ty + dy[i];
        if(cx >=1 && cx <=N && cy >=1 && cy <=N && map[cx][cy].cost!=0 && visit[cx][cy]!=1){
            visit[cx][cy]=1;
            dfs(cx, cy, tm + map[cx][cy].time, cst + map[cx][cy].cost);
            visit[cx][cy]=0;
        }
    }
}


int main(){
    int total;
    scanf("%d", &total );
    while(total--){
        scanf("%d %d %d", &N, &M, &K);
        for(int i=0; i < K ; i++){
            scanf("%d %d %d %d", &q, &w, &e, &r);
            cnt temp;
            temp.cost=e;
            temp.time=r;
            map[q][r] = temp;
        }

        int ans = dfs(1,1,0,0);
       
        if(ans > 0) printf("%d\n",ans);
        else printf("Poor KCM\n");


        for(int i=1; i <= N ; i++){
            for(int j=1; j <= N ; j++){
                cnt temp;
                temp.cost=e;
                temp.time=r;
                map[i][j]=temp;
            }
        }
    }
}

