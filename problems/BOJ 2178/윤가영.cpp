#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int temp, N, M;
int map[101][101];
int val[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    val[x][y] = 1;

    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1<=nx && nx<=N && 1<=ny && ny <=M){
                if(val[nx][ny]==0 && map[nx][ny]==1){
                    q.push(make_pair(nx, ny));
                    val[nx][ny] = val[x][y] + 1;
                }
                else if(val[nx][ny]==0) val[nx][ny]=-1;
            }
        }


    }
}


int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
              scanf("%1d", &map[i][j]);
        }
    }

    bfs(1,1);
    printf("%d\n", val[N][M]);
}