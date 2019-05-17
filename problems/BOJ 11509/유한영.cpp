
#include <iostream>
using namespace std;
int main() {
    int N,tmp,result = 0;
    int arrow[1000001];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(arrow[tmp]>0){
            arrow[tmp]--;
            arrow[tmp-1]++;
        }
        else if(arrow[tmp]==0){
            arrow[tmp-1]++;
            result ++;
        }
    }
    cout<<result;
    return 0;
}
