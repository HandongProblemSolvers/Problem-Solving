//BOJ 4343 - Arctic Network
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> PAIR;
typedef struct Tree{
    int p1, p2;
    double d;
}T;

int N, S, P, parent[501];
PAIR pos[501];
T t[250001];

double getDist(PAIR &a, PAIR &b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int find(int n){
    if(parent[n] < 0) return n;
    parent[n] = find(parent[n]);
    return parent[n];
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[b] = a;
    return true;
}

bool cmp(T a, T b){
    if(a.d < b.d) return true;
    return false;
}

int main(){
    scanf("%d", &N);
    while(N--){
        vector<double> ans;
        memset(parent, -1, sizeof(parent));
        memset(t, 0, sizeof(t));
        scanf("%d %d", &S, &P);
        for(int i = 0; i < P; i++){
            scanf("%d %d", &pos[i].first, &pos[i].second);
        }

        int cnt = 0;
        for(int i = 0; i < P; i++){
            for(int j = i+1; j < P; j++){
                t[cnt].p1 = i;
                t[cnt].p2 = j;
                t[cnt].d = getDist(pos[i], pos[j]);
                cnt++;
            }
        }

        sort(t, t+cnt, cmp);

        for(int i = 0; i < cnt; i++){
            if(merge(t[i].p1, t[i].p2)){
                ans.push_back(t[i].d);
            }
        }

        int loc = ans.size();
        printf("%.2f\n", ans[loc-S]);

        ans.clear();
    }
    return 0;
}