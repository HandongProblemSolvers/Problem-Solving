#include <iostream>
#include <string>
using namespace std;

string S,T;
const int MAX_SIZE = 1000005;
int fail[MAX_SIZE],index[MAX_SIZE];
char memo[MAX_SIZE];

void f() 
{
    int tlen = T.size();
    int begin = 1;
    int m = 0;

    while(begin+m<tlen) {
        if(T[begin+m]==T[m]){
            fail[begin+m] = m+1;
            m++;
        } else {
            if(m==0){
                begin++;
            } else {
                begin += m-fail[m-1];
                m = fail[m-1];
            }
        }
    }
}

int main(void)
{
    cin>>S>>T;
    f();

    int si = 0, ti = 0, i = 0;

    while(si<S.size()) {
        while(S[si]!=T[ti] && ti>0){
            ti = fail[ti-1];
        }
        if(S[si]==T[ti]){
            if(ti==T.size()-1) {
                ti = i-T.size() >=0 ? index[i-T.size()] : 0;
                i -= (T.size()-1);
            } else {
                memo[i] = S[si];
                index[i] = ti+1;
                ti++; i++;
            }
        } else {
            memo[i++] = S[si];
        }
        si++;
    }
    memo[i] = '\0';

    cout << memo;
 
    return 0;
}