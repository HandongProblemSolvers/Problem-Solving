#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 500;
const int INF = 987654321;
int N;
pair<int, int> matrix[maxN];
int dp[maxN][maxN];

int calNum(int s, int e){
    if(s == e) return 0;
    int &result = dp[s][e];
    if(result != -1) return result;
    result = INF;

    for(int i = s; i < e; i++){
        result = min(result, calNum(i + 1, e) + calNum(s, i) + 
        matrix[s].first * matrix[i].second * matrix[e].second);
    }
    return result;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &matrix[i].first, &matrix[i].second);
    memset(dp, -1, sizeof(dp));
    printf("%d", calNum(0, N - 1));
    return 0;
}