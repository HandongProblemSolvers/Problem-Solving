//BOJ7453 합이 0인 네 정수
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 4001
typedef long long ll;

int n;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
vector<ll> AB, CD;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    ll ans = 0;
    for(int i = 0; i < AB.size(); i++){
        ans += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);
    }

    printf("%lld", ans);

    return 0;
}