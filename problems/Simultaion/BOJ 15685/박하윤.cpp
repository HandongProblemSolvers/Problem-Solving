#include <cstdio>
#include <vector>
using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

int main(){
    int N;
    scanf("%d", &N);

    int x,y,d,g;
    int map[101][101] = {0};
    int ans = 0;

    while(N--){
        scanf("%d %d %d %d",&x, &y, &d, &g);
        vector<int> dir;
        dir.push_back(d); 

        for(int j = 1;j <= g; j++){
            int len = (int)dir.size() - 1;

            for(int h = len; h >= 0; h--) // 반대방향으로 1씩 더한 값 => 현 세대의 방향값
                dir.push_back((dir[h]+1) % 4);
        }

        map[y][x]++;
        for(int i = 0;i < dir.size(); i++){
            y = y + dy[dir[i]];
            x = x + dx[dir[i]];

            map[y][x]++;
        }
    }

    for(int i = 0; i < 100; i++){ // 100, 100 안에 있는 것만
        for(int j = 0; j < 100; j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])  // 4 꼭짓점 모두 1일 경우
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
