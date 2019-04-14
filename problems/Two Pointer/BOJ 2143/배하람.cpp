#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> BS;
ll A[1005],B[1005];
ll T,AS;
int N,M;

int main(void)
{
    scanf("%lld",&T);
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%lld",&A[i]);
    scanf("%d",&M);
    for(int i=1; i<=M; i++) scanf("%lld",&B[i]);

    for(int i=2; i<=N; i++) A[i] = A[i-1] + A[i];
    for(int i=2; i<=M; i++) B[i] = B[i-1] + B[i];

    for(int i=1; i<=M; i++)
        for(int j=i; j<=M; j++)
            BS.push_back(B[j] - B[i-1]);

    sort(BS.begin(),BS.end());

    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            ll D = A[j] - A[i-1];
            auto p = equal_range(BS.begin(),BS.end(),T-D);
            AS += distance(p.first,p.second);
        }
    }

    printf("%lld",AS);

    return 0;
}