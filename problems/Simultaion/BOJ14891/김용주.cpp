//BOJ14891 톱니바퀴
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int wheel[5][9], K, n, d, rpos[5], lpos[5];
bool visit[5];
  
void spin(int cur, int dir){
    if(visit[cur]) return;
    visit[cur] = true;

    bool right = false, left = false;

    if(cur + 1 <= 4 && wheel[cur][rpos[cur]] != wheel[cur+1][lpos[cur+1]])
        right = true;

    if(cur - 1 >= 1 && wheel[cur][lpos[cur]] != wheel[cur-1][rpos[cur-1]])
        left = true;

    rpos[cur] = (8 + rpos[cur] - dir) % 8;
    lpos[cur] = (8 + lpos[cur] - dir) % 8;

    // for(int i = 1; i < 5; i++){
    //     printf("%d: %d %d %d %d\n", cur, rpos[i], lpos[i],wheel[i][rpos[i]], wheel[i][lpos[i]]);
    // }

    if(right) spin(cur + 1, (-1) * dir);
    if(left) spin(cur - 1, (-1) * dir);
}

int main(){
    for(int i = 1; i <= 4; i++)
        for(int j = 0; j < 8; j++)
            scanf("%1d", &wheel[i][j]);

    scanf("%d", &K);
    for(int i = 0; i < 5; i++){
        rpos[i] = 2;
        lpos[i] = 6;
    }

    while(K--){
        memset(visit, 0, sizeof(visit));
        scanf("%d %d", &n, &d);
        spin(n, d);
        // for(int i = 1; i < 5; i++){
        //     printf("%d: %d %d\n", i, rpos[i], lpos[i]);
        // }
    }

    int ans = 0;
    for(int i = 1; i <= 4; i++){
        int pos = (8 + rpos[i] - 2) % 8;
        ans += wheel[i][pos] << (i-1);
    }

    printf("%d\n", ans);
    return 0;
}