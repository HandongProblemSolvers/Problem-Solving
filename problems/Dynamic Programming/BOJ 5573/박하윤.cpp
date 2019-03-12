#include <cstdio>
#define max 1001
using namespace std;
int H, W, N;
int map[max][max];
int dp[max][max];

int main(){
    scanf("%d %d %d", &H, &W, &N);
    dp[0][0] = N - 1;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){ 
                dp[i][j+1] += (dp[i][j]+1)/2;
                dp[i+1][j] += (dp[i][j])/2;
            }
            else {
                dp[i+1][j] += (dp[i][j]+1)/2;
                dp[i][j+1] += (dp[i][j])/2;
            }
            map[H][j] = -1;
        }
        map[i][W] = -1;
    }
    int cx = 0, cy = 0;
    while(map[cy][cx] >= 0){
        int c  = (map[cy][cx] + dp[cy][cx]) % 2;
        if(c == 1){
            cx++;
        } else{
            cy++;
        }
    }
    printf("%d %d\n", cy+1, cx+1);
    return 0;
}