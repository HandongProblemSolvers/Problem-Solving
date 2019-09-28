#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct g{
    int x;
    int y;
    int h;
};

int N,D;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int height[51][51],vi[51][51];
char input[51][51];
queue<g> q;
vector<int> real;
const int INF = 2e9;

int main(void)
{
    scanf("%d",&N);

    int sx,sy;
    for(int i=1; i<=N; i++){
        scanf("%s",&input[i][1]);
        for(int j=1; j<=N; j++){
            if(input[i][j]=='K') {
                D++;
            } else if(input[i][j]=='P'){
                sx = i;
                sy = j;
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&height[i][j]);
            real.push_back(height[i][j]);
        }
    }

    sort(real.begin(),real.end());
    real.erase(unique(real.begin(),real.end()),real.end());

    int cnt = real.size();
    int s = 0, e = 0;

    int ans = 2e9;
    while(e<cnt) {
        if(height[sx][sy]<real[s] || height[sx][sy]>real[e]) {
            e++;
            continue;
        }

        memset(vi,0,sizeof(vi));
        q.push({sx,sy,height[sx][sy]});
        vi[sx][sy] = 1;
        int d = 0;
        while(!q.empty()) {
            g temp = q.front(); q.pop();
            for(int i=0; i<8; i++) {
                int _dx = temp.x+dx[i], _dy = temp.y+dy[i];
                if(_dx<1 || _dx>N || _dy<1 || _dy>N) continue;
                if(vi[_dx][_dy]) continue;
                if(height[_dx][_dy]>real[e] || height[_dx][_dy]<real[s]) continue;
                if(input[_dx][_dy]=='K') d++;
                vi[_dx][_dy] = 1;
                q.push({_dx,_dy,height[_dx][_dy]});
            }
        }
        if(d<D) e++;
        else {
            ans = min(ans,real[e]-real[s]);
            s++;
        }
    }

    printf("%d",ans);

    return 0;
}