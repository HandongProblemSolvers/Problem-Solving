//  boj2343
//  Created by Hanyoung Yoo on 29/06/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.

#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 987654321;

int ddr_step(int a,int b){
    int temp;
    if(a>b){
        temp = a;
        a = b;
        b = temp;
    } // a < b
    if(a==0)return 2;
    else if(a==1 && b==2)return 3;
    else if(a==1 && b==3)return 4;
    else if(a==1 && b==4)return 3;
    else if(a==2 && b==3)return 3;
    else if(a==2 && b==4)return 4;
    else if(a==3 && b==4)return 3; // b == 4
    else return 1;
}
int main() {
    int ddr[100002],min=0,N=0;
    int dp[100002][5];
    //input part
    while (1){
        scanf("%d", &ddr[N++]);
        if (ddr[N-1] == 0)break;
    }
    N--;
    
    for(int i=0;i<5;i++)dp[0][i] = inf;
    for(int k=0;k<N;k++){
        if (k == 0)dp[k][0] = 2;
        else {
            if(ddr[k] == ddr[k-1]){
                for(int j=0;j<5;j++){
                    if(dp[k-1][j] != inf)dp[k][j]=dp[k-1][j]+1;
                    else dp[k][j] = inf;
                }
                continue;
            }
            //find min for next
            min = inf;
            for(int j=0;j<5;j++)dp[k][j] = inf;
            for(int j=0;j<5;j++){
                // j == ddr[k-1]
                if(dp[k-1][j] != inf){
                    if(j == ddr[k]){
                        if(min > dp[k-1][j]+1)min = dp[k-1][j]+1;
                    }
                    else if(min > dp[k-1][j] + ddr_step(ddr[k], j)){
                        min = dp[k-1][j] + ddr_step(ddr[k], j);
                    }
                }
                // j == 0
                if(j == 0){
                    dp[k][0] = dp[k-1][0] + ddr_step(ddr[k-1],ddr[k]);
                    continue;
                }
                else if(j == ddr[k] || j == ddr[k-1])continue; // j == ddr[k] -> inf
                else if(dp[k-1][ddr[k]] != inf || dp[k-1][j] != inf){
                    if(dp[k-1][ddr[k]] + ddr_step(j,ddr[k-1]) < dp[k-1][j] + ddr_step(ddr[k],ddr[k-1])){
                        dp[k][j] = dp[k-1][ddr[k]] + ddr_step(j,ddr[k-1]);
                    }
                    else{
                        dp[k][j] = dp[k-1][j] + ddr_step(ddr[k],ddr[k-1]);
                    }
                }
            }
            dp[k][ddr[k-1]] = min;
        }
    }
    min = inf;
    for(int i=0;i<5;i++){
        if(min > dp[N-1][i])min = dp[N-1][i];
    }
    cout<<min;
    return 0;
}

