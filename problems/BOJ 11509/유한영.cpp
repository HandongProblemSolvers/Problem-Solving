#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N,tmp,result = 0,arrow[1000001];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(arrow[tmp])arrow[tmp]--;
        else result ++;
        arrow[tmp-1]++;
    }
    cout<<result;
    return 0;
}
