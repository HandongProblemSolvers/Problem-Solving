#include <iostream>
using namespace std;
int N, M, K, d[251][251], u, v, b, x, y, INF = 1e7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) 
            d[i][j] = (i==j)?0:INF;
    for(int i = 1; i <= M; i++){
        cin>>u>>v>>b;
        d[u][v] = 0;
        d[v][u] = b^1;
    }    
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    cin>>K;
    for(int i = 0; i < K; i++){
        cin>>x>>y;
        cout<<d[x][y]<<"\n";
    }
}
