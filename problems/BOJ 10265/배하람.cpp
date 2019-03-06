#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001];
int n,k,c,u;
int visited[1001];
int dp[1001][1001];

int dfs(int v, int num)
{
    visited[v] = 1;
    if(!visited[a[v]]) 
        num = dfs(a[v],num+1);
    return num;
}

void cleanVisit(int index)
{
    visited[index] = 0;
    if(visited[a[index]]) {
        cleanVisit(a[index]);
    }
}

int ride(int index, int current)
{
    int &ret = dp[index][current];
    if(ret!=-1) return ret;
    //printf("index: %d, current: %d, needs: %d\n",index,current,needs);
    if(index>n) return 0;

    // 묶음을 계산하지 않음 + 태우지 않음
    ret = ride(index+1,current);

    if(!visited[index]) {
        // 묶음을 계산함, 즉 DFS로 방문하게 됨
        int needs = dfs(index,1);
        if(current+needs<=k) {
            // 태우지 않음, 태움
            ret = max(ride(index+1,current+needs)+needs,ride(index+1,current));
        }
        cleanVisit(index);
    }
    return ret;
}

int main(void)
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&u);
        a[i] = u;
    }

    memset(dp,-1,sizeof(dp));
    printf("%d",ride(1,0));

    return 0;
}