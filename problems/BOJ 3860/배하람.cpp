#include <cstdio>
#include <vector>
using namespace std;

struct node{int x,y;};
struct edge{node n1,n2; int cost;};
struct endHole{int x,y,cost;};
const int INF = 2e9;
int w,h,g,x,y,e,x1,y1,x2,y2,t;
int maze[31][31],dist[31][31];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
endHole hole[31][31];
vector<edge> graph;

void initialization()
{
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            maze[i][j] = 0;
            endHole eh = {i,j,0};
            hole[i][j] = eh;
        }
    }
    graph.clear();
}

bool bellmanFord()
{
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0;
    for(int i=0; i<w*h-1; i++){
        for(edge e : graph){
            node from = e.n1,to = e.n2;
            int cost = e.cost;
            if(dist[from.x][from.y]==INF) continue;
            if(dist[from.x][from.y]+cost<dist[to.x][to.y]){
                dist[to.x][to.y] = dist[from.x][from.y]+cost;
            }
        }
    }
    bool isThereNegativeCycle = false;
    for(edge e : graph){
        node from = e.n1,to = e.n2;
        int cost = e.cost;
        if(dist[from.x][from.y]==INF) continue;
        if(dist[from.x][from.y]+cost<dist[to.x][to.y]){
            isThereNegativeCycle = true;
            break;
        }
    }
    return isThereNegativeCycle;
}

void graphConstruction()
{
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(i==w-1 && j==h-1) break;
            if(maze[i][j]==-1) continue;
            if(maze[i][j]==0){
                for(int k=0; k<4; k++){
                    int _dx = i+dx[k], _dy = j+dy[k];
                    if(_dx<0 || _dx>=w || _dy<0 || _dy>=h) continue;
                    if(maze[_dx][_dy]==-1) continue;
                    graph.push_back({i,j,_dx,_dy,1});
                }
            } else if(maze[i][j]==-2){
                graph.push_back({i,j,hole[i][j].x,hole[i][j].y,hole[i][j].cost});
            }
        }
    }
}

int main(void)
{
    while(true){
        scanf("%d%d",&w,&h);
        if(!w&&!h) break;
        scanf("%d",&g);
        while(g--){
            scanf("%d%d",&x,&y);
            maze[x][y] = -1;
        }
        scanf("%d",&e);
        while(e--){
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&t);
            maze[x1][y1] = -2;
            endHole eh = {x2,y2,t};
            hole[x1][y1] = eh;
        }
        graphConstruction();
        bool isThereNagativeCycle = bellmanFord();
        if(isThereNagativeCycle) printf("Never\n");
        else if(dist[w-1][h-1]==INF) printf("Impossible\n");
        else printf("%d\n",dist[w-1][h-1]);
        initialization();
    }
    return 0;
}