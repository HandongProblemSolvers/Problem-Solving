#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

struct pp { int num; int dir; };
string top;
deque<int> t[5];
vector<pp> query;
int k,n,d;

void rotate(int index, int dir)
{
    if(dir == 1){
        int back = t[index].back();
        t[index].pop_back();
        t[index].push_front(back);
    } else{
        int front = t[index].front();
        t[index].pop_front();
        t[index].push_back(front);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    for(int i=1; i<=4; i++){
        cin >> top;
        for(char c : top)
            t[i].push_back(c-'0');
    }
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> n >> d;
        query.push_back({n,d});
    }

    for(pp q : query){
        int cur = q.num, left = q.num-1;
        int dir = q.dir;
        int indexToDir[5] = {0,0,0,0,0};
        indexToDir[cur] = dir;
        while(left){
            if(t[left][2]!=t[cur][6]){
                dir *= -1;
                indexToDir[left] = dir;
                cur = left;
                left--;
            } else break;
        }
        int right = q.num+1;
        cur = q.num;
        dir = q.dir;
        while(right<=4){
            if(t[right][6]!=t[cur][2]){
                dir *= -1;
                indexToDir[right] = dir;
                cur = right;
                right++;
            } else break;
        }
        for(int i=1; i<=4; i++){
            if(!indexToDir[i]) continue;
            rotate(i,indexToDir[i]);
        }
    }

    int ans = 0;
    ans += t[1][0]?1:0;
    ans += t[2][0]?2:0;
    ans += t[3][0]?4:0;
    ans += t[4][0]?8:0;

    cout << ans << '\n';
    return 0;
}