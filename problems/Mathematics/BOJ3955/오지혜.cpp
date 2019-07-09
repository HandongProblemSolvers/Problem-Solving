//BOJ_3955

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO {
    long long gcd;
    long long s;
    long long t;
};

vector<long long> s, t, r, q;

//K*s+C*t=gcd(K,C)
//to find GCD of K and C and s, t

INFO GCD(long long k, long long c) {
    s = { 1,0 };
    t = { 0,1 };
    r = { k,c };
    
    while (1)
    {
        //q=a/b
        //r=a%b
        long long r1 = r[r.size() - 2];
        long long r2 = r[r.size() - 1];
        q.push_back(r1 / r2);
        r.push_back(r1 % r2);
        
        //when find gcd
        if (r[r.size() - 1] == 0)
            break;
        
        //s=s1-s2*q
        //t=t1-t2*q
        long long s1 = s[s.size() - 2];
        long long s2 = s[s.size() - 1];
        
        long long t1 = t[t.size() - 2];
        long long t2 = t[t.size() - 1];
        
        long long q1 = q[q.size() - 1];
        s.push_back(s1 - s2 * q1);
        t.push_back(t1 - t2 * q1);
    }
    
    INFO infor = { r[r.size() - 2], s[s.size() - 1], t[t.size() - 1] };
    
    while(infor.t<0)
        infor.t+=k;
    
    s.clear();
    t.clear();
    r.clear();
    q.clear();
    
    return infor;
}
int main()
{
    int t;
    scanf("%d", &t);
    long long K, C;
    
    for(int i=0; i<t; i++){
        scanf("%lld %lld", &K, &C);
        
        //one candy per bag
        if(C==1){
            if(K+1<=1e9)
                printf("%lld\n", K+1);
            else
                printf("IMPOSSIBLE\n");
            continue;
        }
        //one person
        else if(K==1){
            printf("1\n");
            continue;
        }
        //we have to find in the case of gcd is 1 to solve particular solution
        else if(GCD(K, C).gcd!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        else{
            INFO infor = GCD(K, C);
 
            if(infor.t>1e9){
                printf("IMPOSSIBLE\n");
            }
            else{
                printf("%lld\n", infor.t);
            }
        }
    }
        
    return 0;
}



