#include <cstdio>

int path[1005][1005];
int dp[1005][1005][2];
int n,h,w;

int main(void)
{
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            scanf("%d",&path[i][j]);
        }
    }

    dp[1][1][1] = path[1][1] ? (n-1)/2 + (n-1)%2 : (n-1)/2;
    dp[1][1][0] = !path[1][1] ? (n-1)/2 + (n-1)%2 : (n-1)/2;

    for(int i=2; i<=h; i++){
        dp[i][1][1] = path[i][1] ? dp[i-1][1][0]/2 + dp[i-1][1][0]%2 : dp[i-1][1][0]/2;
        dp[i][1][0] = !path[i][1] ? dp[i-1][1][0]/2 + dp[i-1][1][0]%2 : dp[i-1][1][0]/2;
    }
    for(int i=2; i<=w; i++){
        dp[1][i][1] = path[1][i] ? dp[1][i-1][1]/2 + dp[1][i-1][1]%2 : dp[1][i-1][1]/2;
        dp[1][i][0] = !path[1][i] ? dp[1][i-1][1]/2 + dp[1][i-1][1]%2 : dp[1][i-1][1]/2;
    }

    for(int i=2; i<=h; i++){
        for(int j=2; j<=w; j++){
            int in = dp[i-1][j][0] + dp[i][j-1][1];
            dp[i][j][1] = path[i][j] ? in/2 + in%2 : in/2;
            dp[i][j][0] = !path[i][j] ? in/2 + in%2 : in/2;
        }
    }

    int r = 1, c = 1;
    while(r<=h && c<=w) {
        int visit = dp[r][c][0]+dp[r][c][1];
        path[r][c] = visit%2==0 ? path[r][c] : !path[r][c];
        path[r][c] ? c++ : r++;
    }

    printf("%d %d",r,c);

    return 0;
}