#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct homework{
    int deadline;
    int cup;

    bool operator<(const homework& rhs) const{
        if(deadline==rhs.deadline){
            return cup > rhs.cup;
        }
        return deadline < rhs.deadline;
    }
};

int N,d,c;
vector<homework> h;
priority_queue<int> pq;

int main(void)
{
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d%d",&d,&c);
        h.push_back({d,c});
    }

    sort(h.begin(),h.end());

    int cur = 1, ans = 0;
    for(int i=0; i<N; i++){
        if(cur <= h[i].deadline){
            cur++;
            ans += h[i].cup;
            pq.push(-h[i].cup);
        } else if(!pq.empty() && (-pq.top()) < h[i].cup){
            ans += (pq.top() + h[i].cup);
            pq.pop();
            pq.push(-h[i].cup);
        }
    }
    printf("%d\n",ans);

    return 0;
}