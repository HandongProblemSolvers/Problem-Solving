#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>

using namespace std;
int direction[4][2] ={{1,0},{0,-1},{-1,0},{0,1}};
int check[101][101]={0,};

/*void print(){
    cout<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<check[i][j]<<' ';
        }
        cout<<endl;
    }
}
 */
//  0 1 x = y
// -1 0 y = -x
void draw_point(vector<pair<int, int>> dots,int n,int status){
    int len = (int)dots.size();
    pair<int,int> tmp;
    if(n == 0)return;
    for(int i=len-1;i>=0;i--){
        tmp.first = dots[len-1].first+(dots[i].second-dots[len-1].second)*(1);
        tmp.second = dots[len-1].second+(dots[i].first-dots[len-1].first)*(-1);
        check[tmp.first][tmp.second]=1;
        dots.push_back(tmp);
    }
    //print();
    draw_point(dots, n-1,(status+1)%4);
}
int main(int argc, const char * argv[]) {
    int N;
    int x,y,d,g,result = 0;
    cin>> N;
    for(int i=0;i<N;i++){
        cin>>x>>y>>d>>g; // d: 0 (1,0) 1 (0,-1) 2 (-1,0) 3 (0,1) state가 있으면 됨.
        vector<pair<int,int>> dots;
        pair<int, int> tmp;
        check[y][x]=1;
        tmp.first = y;
        tmp.second = x;
        dots.push_back(tmp);
        
        tmp.first = y+direction[d][1];
        tmp.second = x+direction[d][0];
        check[tmp.first][tmp.second]=1;
        dots.push_back(tmp);
        
        draw_point(dots, g, (d+1)%4);
        dots.clear();
    }
    for(int j=0;j<101;j++){
        for(int k=0;k<101;k++){
            if(check[j][k] == 1 && check[j+1][k] == 1 && check[j][k+1] == 1 && check[j+1][k+1])result++;
        }
    }
    cout<<result;
    return 0;
}
