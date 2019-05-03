#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

double dp[5001][5001] = { 0, };
double dp_combination(int n, int k) {
    if (dp[n][k] == 0) {
        if (n == k || k == 0) {
            dp[n][k] = 1;
            return 1;
        }
        else {
            dp[n][k] = dp_combination(n - 1, k - 1) + dp_combination(n - 1, k);
            return dp[n][k];
        }
    }
    return dp[n][k];
}
int main(int argc, const char * argv[]) {
    
    int M,K,color,cnt=0;
    vector<int> shingle;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>color;
        shingle.push_back(color);
        cnt+=color;
    }
    cin>>K;
    
    double result =0;
    for(int i=0;i<M;i++){
        int n = shingle[i];
        if(K <= n)result += dp_combination(n,K);
    }
    result = result / dp_combination(cnt,K);
    printf("%.10lf",result);
    return 0;
}
