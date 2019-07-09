#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int T,K,C;
int s0,s1,t0,t1,r0,r1,q;

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}

void eea(int a, int b){
    s0=1, s1=0;
    t0=0, t1=1;
    r0=a, r1=b;

    int temp = 0;
    while(r1){
        q = r0/r1;
        temp = r0;
        r0 = r1;
        r1 = temp - r1*q;
        temp = s0;
        s0 = s1;
        s1 = temp - s1*q;
        temp = t0;
        t0 = t1;
        t1 = temp - t1*q;
    }
}

int main(void)
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&K,&C);
        if(gcd(K,C)!=1) puts("IMPOSSIBLE");
        else{
            eea(K,C);
            int maxV = ceil(min(double(-s0)/C,double(t0)/K))-1;
            if(t0-1e9>maxV*K) puts("IMPOSSIBLE");
            else printf("%d\n",t0-maxV*K);
        }
    }
    return 0;
}