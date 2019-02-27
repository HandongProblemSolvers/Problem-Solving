#include <cstdio>
#include <cstring>
using namespace std;

const int max = 101;
int N, K, T;
int dp[max][max][2];

int sequence(int len, int total, int bit){
    if(len >= N || total > K) return 0;
    if(len + 1 == N && total == K) return 1;
    int &result = dp[len][total][bit];

    if(result != -1) return result;
    result = sequence(len+1, total, 0) + sequence(len+1, total + bit*1, 1);
    return result;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", sequence(0, 0, 0) + sequence(0, 0, 1));
    }
    return 0;
}