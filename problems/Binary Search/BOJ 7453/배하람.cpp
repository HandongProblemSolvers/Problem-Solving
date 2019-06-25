#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int _size = 4001;

int A[_size],B[_size],C[_size],D[_size];
int n;
vector<int> AB,CD;

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            AB.push_back(A[i]+B[j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            CD.push_back(C[i]+D[j]);
        }
    }

    sort(CD.begin(),CD.end());

    ll ans = 0LL;
    for(int ab : AB) {
        auto it1 = lower_bound(CD.begin(),CD.end(),-ab);
        auto it2 = upper_bound(CD.begin(),CD.end(),-ab);
        ans += distance(it1,it2);
    }

    printf("%lld\n",ans);

    return 0;
}