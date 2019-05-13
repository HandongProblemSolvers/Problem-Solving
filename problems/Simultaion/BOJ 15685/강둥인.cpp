#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 점이 놓여있으면 true, 없으면 false
bool map[102][102];

//끝점
int end_x = 0;
int end_y = 0;


//방향
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};


int checkRect() {
    int result = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (map[i][j] == true && map[i][j+1] == true && 
            map[i+1][j] == true && map[i+1][j+1] == true) {
                result++;
            }
        }
    }
    return result;
}

void n_generation(vector<int> &v) {
    int size = (int)v.size();

    for (int i = size - 1; i >=0; i--) {
        int dir = (v[i] + 1)%4;

        end_x = end_x + dirx[dir];
        end_y = end_y + diry[dir];

        map[end_x][end_y] = true;

        v.push_back(dir);
    }

}

int main() {
    int N, x, y, d, g;
    vector<int> v;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &y, &x, &d, &g);

        v.clear();
        
        end_x = x;
        end_y = y;

        map[end_x][end_y] = true;

        end_x = x + dirx[d];
        end_y = y + diry[d];

        map[end_x][end_y] = true;
        v.push_back(d);

        for (int j = 0; j < g; j++)
            n_generation(v);    
    }



    printf("%d\n", checkRect());
    return 0;
}
