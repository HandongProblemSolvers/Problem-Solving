//BOJ1781 컵라면
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
#define MAX_N 200001

int N, visit[MAX_N];
vector<P> cup;

bool cmp(P a, P b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cup.push_back({a, b});
    }
    sort(cup.begin(), cup.end(), cmp);

    long long ans = 0;
    for(int i = 0; i < N; i++){
        int a = cup[i].first;
        int b = cup[i].second;
        if(visit[a] > 1) continue;
        while(visit[a]) a--;
        if(a == 0){
            visit[cup[i].first]++;
            continue;
        }
        visit[a]++;
        ans += b;
    }
    printf("%lld", ans);

    return 0;
}