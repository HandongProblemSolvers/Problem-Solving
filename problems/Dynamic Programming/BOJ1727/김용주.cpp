//BOJ1727 커플 만들기
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1001

int n, m, man[MAX_N], woman[MAX_N], dp[MAX_N][MAX_N];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &man[i]);

    for(int i = 0; i < m; i++)
        scanf("%d", &woman[i]);

    sort(man, man + n);
    sort(woman, woman + m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int &ret = dp[i+1][j+1];
            ret = dp[i][j] + abs(man[i] - woman[j]);
            if(i > j) ret = min(ret, dp[i][j+1]);
            if(i < j) ret = min(ret, dp[i+1][j]);
        }
    }

    printf("%d", dp[n][m]);

    return 0;
}