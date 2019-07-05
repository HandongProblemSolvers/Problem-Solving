//BOJ17232 생명
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101

int N, M, T, K, a, b, dp[MAX_N][MAX_N];
char board[MAX_N][MAX_N], ch;
bool life[MAX_N][MAX_N];

int main(){
    scanf("%d %d %d", &N, &M, &T);
    scanf("%d %d %d", &K, &a, &b);

    for(int i = 1; i <= N; i++)
        scanf("%s", &board[i][1]);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            life[i][j] = (board[i][j] == '*') ? 1 : 0; 

    while(T--){
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                if(!i || !j) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + life[i][j];
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                int up = (i-K-1 > 0) ? i-K-1 : 0;
                int down = (i+K < N) ? i+K : N; 
                int left = (j-K-1 > 0) ? j-K-1 : 0;
                int right = (j+K < M) ? j+K : M;
                int integral = dp[down][right] - dp[down][left] - dp[up][right] + dp[up][left] - life[i][j];

                if(life[i][j]){
                    if(integral < a || integral > b) life[i][j] = 0;
                    else life[i][j] = 1;
                }
                else
                    if(a < integral && integral <= b) life[i][j] = 1;
            }
        }
    }
 
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(life[i][j]) printf("*");
            else printf(".");
        }
        printf("\n");
    }

    return 0;
}