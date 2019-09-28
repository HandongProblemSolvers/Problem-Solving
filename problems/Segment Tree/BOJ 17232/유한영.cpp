//  Created by Hanyoung Yoo on 04/07/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.


#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char map[101][101];
    int value[101][101];
    int N,M,T;
    int K,a,b;
    vector<pair<int,int>> v;
    cin>>N>>M>>T;
    cin>>K>>a>>b;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j] == '*')v.push_back(make_pair(i, j));
        }
    }
    for(int i=0;i<T;i++){
        memset(value,0,sizeof(value));
        while(v.size() != 0){
            for(int k= (-1 * K) ; k <= K ; k++){
                if(v.back().first + k >=0 && v.back().first + k < N){
                    for(int j = (-1 * K) ; j <= K ; j++){
                        if(k == 0 && j == 0)continue;
                        if(v.back().second + j >=0 && v.back().second+j < M){
                            value[v.back().first+k][v.back().second+j]++;
                        }
                    }
                }
            }
            v.pop_back();
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(map[j][k] == '*'){
                    if(value[j][k] >= a && value[j][k] <= b){ // 생존
                        v.push_back(make_pair(j,k));
                    }
                    else map[j][k] = '.'; // 외로움 + 과밀
                }
                else{
                    if(value[j][k] > a && value[j][k] <= b){ // 탄생
                        map[j][k] = '*';
                        v.push_back(make_pair(j,k));
                    }
                }
            }
        }
    }
    for(int p=0;p<N;p++){
        for(int q=0;q<M;q++){
            cout<<map[p][q];
        }
        cout<<endl;
    }
    return 0;
}
