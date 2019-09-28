// Fenwick_공장_7578
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
int N, tree[500001], A[500001], B[1000001];

void update(int i){
    while(i <= N){
        tree[i] += 1;
        i += (i & -i);
    }
}

int sum (int i ){
    int ret = 0;
    while(i > 0){
        ret += tree[i]; // 부분합
        i -= (i & -i);
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for(int i = 1; i <= N; i++){
        int val;
        scanf("%d", &val);
        B[val] = i;     // 해당 val의 인덱스를 저장
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        int valA = A[i];
        int idxB  = B[valA];

        ans += (ll)sum(N) - (ll)sum(idxB);
        update(idxB);
    }

    printf("%lld", ans);
    return 0;
}