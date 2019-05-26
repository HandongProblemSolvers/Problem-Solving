#include <cstdio>
#include <vector>
using namespace std;

struct co{int x,y;};
char grid[101][101];
int n,ans;
vector<co> dot;

bool isLine(co c1, co c2, co c3){
    return ((c1.x*c2.y+c2.x*c3.y+c3.x*c1.y)-(c1.y*c2.x+c2.y*c3.x+c3.y*c1.x))==0;
}

void dfs(int index, vector<co> pos)
{
    if(pos.size()==3){
        ans += isLine(pos[0],pos[1],pos[2])?1:0;
        return;
    }
    for(int i=index+1; i<dot.size(); i++){
        pos.push_back({dot[i]});
        dfs(i,pos);
        pos.pop_back();
    }
}

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%s",&grid[i][1]); 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]>='A' && grid[i][j]<='Z'){
                dot.push_back({i,j});
            }
        }
    }

    for(int i=0; i<=dot.size()-2; i++){
        vector<co> pos;
        pos.push_back({dot[i]});
        dfs(i,pos);
    }
    printf("%d\n",ans);
    return 0;
}