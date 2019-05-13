//BOJ15685 드래곤커브
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_X 101
#define MAX_D 1 << 10

int n, x, y, d, g, board[MAX_X][MAX_X], dir[MAX_D];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d", &x, &y, &d, &g);

        dir[0] = d;
        int k = 1;
        for(int i = 1; i <= g; i++){
            int n = (1 << i) - 1;
            while(k <= n){
                dir[k] = (dir[n-k]+1)%4;
                // printf("%d, %d: %d\n", n, k, dir[k]);
                k++;
            }
        }

        board[x][y] = 1;
        for(int i = 0; i < (1 << g); i++){
            x += dx[dir[i]];
            y += dy[dir[i]];
            board[x][y] = 1;
        }        
    }

    int ans = 0;
    for(int i = 0; i < MAX_X-1; i++){
        for(int j = 0; j < MAX_X-1; j++){
            if(board[i][j] && board[i+1][j] && board[i+1][j+1] && board[i][j+1]) ans++; 
        }
    }

    printf("%d", ans);
    return 0;
}