#include <bits/stdc++.h>
using namespace std;
int H, W, N, m[1005][1005], D[1005][1005], x=1, y=1;
void f(int a, int b){
    if(x==1+H || y==1+W) return;
    m[x][y] ? f(x,y++) : f(x++,y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>H>>W>>N;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin>>m[i][j];
    D[1][1] = N-1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            D[i][j+1] += m[i][j] ? D[i][j]/2+D[i][j]%2 : D[i][j]/2;
            D[i+1][j] += !m[i][j] ? D[i][j]/2+D[i][j]%2 : D[i][j]/2;
            m[i][j] = D[i][j]%2 ? m[i][j]^1 : m[i][j];
        }
    }
    f(1,1);
    cout<<x<<" "<<y;
}