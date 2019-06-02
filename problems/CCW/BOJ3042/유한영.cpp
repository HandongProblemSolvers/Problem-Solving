#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int compute_ccw(int x1,int y1, int x2, int y2,int x3,int y3){
    int v1_x,v1_y,v2_x,v2_y;
    v1_x = x1-x2;
    v1_y = y1-y2;
    v2_x = x1-x3;
    v2_y = y1-y3;
    return (v1_x * v2_y - v1_y*v2_x);
}

int main() {
    
    int N,result = 0;
    vector<pair<int,int>> dots;
    char tmp;
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            if(tmp != '.'){
                pair<int,int> xy;
                xy.first = i;
                xy.second = j;
                dots.push_back(xy);
            }
        }
    }
    for(int i=0;i<dots.size();i++){
        for(int j=i+1;j<dots.size();j++){
            for(int k=j+1;k<dots.size();k++){
                if(compute_ccw(dots[i].first, dots[i].second, dots[j].first, dots[j].second,dots[k].first,dots[k].second)==0)result ++;
            }
        }
    }
    cout<<result;
    return 0;
}
