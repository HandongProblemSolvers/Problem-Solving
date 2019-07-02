
//BOJ_2342

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> V;
V v;
long n;
int dp[5][5][100001];


int power(int current, int next){

    //case 1: at first
    if(current == 0){
        return 2;
    }
    //case 2: same position
    else if(current == next){
        return 1;
    }
    //case 3: opposite position
    else if(abs(current - next) == 2){
        return 4;
    }
    //case 4: near
    else{
        return 3;
    }
    
}

int choose(int a, int b, int next){
    
    if(next == n)
        return 0;
    
    if(dp[a][b][next] != -1)
        return dp[a][b][next];
    
    //calculate each value to choose minimum
    int l = choose(v[next], b, next + 1) + power(a, v[next]);
    int r = choose(a, v[next], next + 1) + power(b, v[next]);
    
    //store minimum
    return dp[a][b][next] = min(l,r);
    
}

//using DP
int main(){
    
    while(1){
        
        int temp;
        scanf("%d", &temp);
        
        if(temp == 0){
            break;
        }
        v.push_back(temp);
    }
    
    memset(dp, -1, sizeof(dp));
    n = v.size();
    
    printf("%d", choose(0, 0, 0));
    
    return 0;
}

