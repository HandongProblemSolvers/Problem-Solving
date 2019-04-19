#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[11];
int W[11][11];
int N;
int ans = 0;
int first;

void dfs(int node, int sum, int cnt){
    if (!visited[node]){
        visited[node] = 1;
        cnt++;
        for (int i = 0; i < N; i++){
            if (W[node][i] != 0)
                dfs(i, sum + W[node][i], cnt);
        }
        visited[node] = 0;
    }
    if (cnt == N && first == node){ // 다시 처음으로 돌아올 경우
        ans = (ans == 0) ? sum : min(sum, ans);
        return;
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    }
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++){
        first = i;
        dfs(i, 0, 0);
        memset(visited, 0, sizeof(visited));
    }
    printf("%d", ans);
    return 0;
}