// 확장유클리드_캔디분배_3955

#include <cstdio>
typedef long long ll;

ll K, X, C, N;

ll gcd(ll a, ll b){
  return b ? gcd(b, a%b) : a;
}

ll extended_gcd(ll a, ll b){
  ll r, q, t, t1 = 0, t2 = 1, temp = a;
  while (b != 0){
    q = a / b;
    r = a%b;
    t = t1 - q*t2;
    a = b;
    b = r;
    t1 = t2; t2 = t;
  }
    while (t1<0) t1 += temp; // 음수일 경우
    return t1;
}

int main(){
  int T;
  ll ans = 0;
  scanf("%d", &T);
  while(T--){
    scanf("%lld %lld", &K, &C);
    if(gcd(K, C) != 1) printf("IMPOSSIBLE\n");
    else {
       ans = extended_gcd(K, C);
      if (ans > 1000000000) printf("IMPOSSIBLE\n");
      else printf("%lld\n", ans);
      }
  }
  return 0;
}
