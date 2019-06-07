#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    const int inf = 2147483640;
    int N;
    int abcd[4][4001];
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            cin>>abcd[j][i];
        }
    }
    vector<int> a;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a.push_back(abcd[0][i]+abcd[1][j]);
        }
    }
    vector<int> b;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            b.push_back(abcd[2][i]+abcd[3][j]);
        }
    }
    a.push_back(inf);
    a.push_back(inf*(-1));
    b.push_back(inf+1);
    b.push_back((inf+1)*(-1));
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long result = 0;
    int front = 0, rear = N*N+1;
    long current_val_a, current_val_b;
    long current_cnt_a = 0, current_cnt_b = 0;
    for(;;){
        if(abs(a[front])>abs(b[rear])){
            if(a[front]<0 && b[rear]>=0)front++;
            else rear--;
        }
        else if(abs(a[front])<abs(b[rear])){
            if(a[front]<=0 && b[rear]>0)rear--;
            else front++;
        }
        else{
            current_val_a = a[front];
            do{
                current_cnt_a++;
                front++;
            }while(a[front] == current_val_a);
            
            current_val_b = b[rear];
            do{
                current_cnt_b++;
                rear--;
            }while(b[rear] == current_val_b);
            
            result += current_cnt_a * current_cnt_b;
            current_cnt_a=0;
            current_cnt_b=0;
        }
        if(rear == 0 || front == N*N+2)break;
    }
    cout << result;
    return 0;
}
