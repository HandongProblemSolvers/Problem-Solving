
//  Created by Hanyoung Yoo on 16/07/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.


#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int map[252][252];
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    int u,v,b;
    for(int i=0;i<m;i++){
        cin>>u>>v>>b;
        if( b == 0 ){
            map[u][v] = 0 ;
            map[v][u] = 1 ;
        }
        else {
            map[u][v] = 0 ;
            map[v][u] = 0 ;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                map[j][k] = min(map[j][k] , map[j][i] + map[i][k] );
            }
        }
    }
    int k,s,e;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>s>>e;
        cout<<map[s][e]<<"\n";
    }
    return 0;
}

