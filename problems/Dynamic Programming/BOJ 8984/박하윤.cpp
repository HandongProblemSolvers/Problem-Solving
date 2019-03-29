#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int N, L;
pair<int, int> stick[MAX];
vector <int> t, d;
long long dp_T[MAX];
long long dp_D[MAX];

int main(){
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &stick[i].first, &stick[i].second);
        t.push_back(stick[i].first);
        d.push_back(stick[i].second);
    }
    sort(stick, stick+N);
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());

    t.erase(unique(t.begin(), t.end()), t.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    long long ans = 0;

    for(int i = 0; i < N; i++){
        int t_idx = lower_bound(t.begin(), t.end(), stick[i].first) - t.begin(); // 말그대로 index 구하는거! => len 구하기 위한 Idx
        int d_idx = lower_bound(d.begin(), d.end(), stick[i].second) - d.begin();
        int len = L + (abs(stick[i].second - stick[i].first));

        long long top = dp_T[t_idx]; 
        long long down = dp_D[d_idx];

        dp_T[t_idx] = max(top, down + len);
        dp_D[d_idx] = max(down, top + len);
        ans = max(dp_T[t_idx], max(ans, dp_D[d_idx]));
    }
    printf("%lld\n", ans);
    return 0;
}