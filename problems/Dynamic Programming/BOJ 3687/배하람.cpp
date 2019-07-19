#include <cstdio>
#include <cstring>
using namespace std;

int num[10] = {6,2,5,5,4,5,6,3,7,6};
int dp[101][101];
int tc,n;

void track(int n, int k, bool isFirst)
{
    if(!dp[n][k]) return;
    int start = isFirst ? 1 : 0;
    for(int i=start; i<10; i++){
        if(n >= num[i]){
            if(dp[n-num[i]][k-1]){
                printf("%d",i);
                track(n-num[i],k-1,false);
                break;
            }
        }
    }
}

bool match(int n, int k, bool isFirst)
{
    int &ret = dp[n][k];
    if(ret != -1) return ret;

    if(n==0 && k==0) return ret = 1;
    if(n==1 || k==0) return ret = 0;

    int start = isFirst ? 1 : 0;
    for(int i=start; i<=9; i++){
        if(n >= num[i]){
            if(match(n-num[i],k-1,false)){
                return ret = 1;
            }
        }
    }
    return ret = 0;
}

int main(void)
{
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        int k = n%7==0 ? n/7 : n/7+1;
        match(n,k,true);
        track(n,k,true);
        printf(" ");
        if(n%2==0) for(int i=1; i<=n/2; i++) printf("1");
        else {
            printf("7");
            for(int i=1; i<=n/2-1; i++) printf("1");
        }
        puts("");
    }
    return 0;
}