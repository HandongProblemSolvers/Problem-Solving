
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int root[501];
int _rank[501];
int cnt;

float getdist(int x1, int y1, int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int _find(int x) {
    if (root[x] == x)return x;
    else return root[x] = _find(root[x]);
}
void _union(int x, int y){
    x = _find(x);
    y = _find(y);
    if(x==y)return;
    if(_rank[x] < _rank[y]){
        root[x] = root[y];
        cnt--;
    }
    else {
        root[y] = root[x];
        cnt--;
        if(_rank[x] == _rank[y]){
            _rank[x]++;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(2);
    int N, S, P,i,j,k;
    int array[501][2];
    vector<pair<float,pair<int,int>>> distlist;
    pair<float,pair<int,int>> tmp;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>S>>P;
        cnt = P;
        for(j=0;j<P;j++)
            cin>>array[j][0]>>array[j][1];
        for(j=0;j<P;j++){
            for(k=j+1;k<P;k++){
                if(j==k)continue;
                tmp.first = getdist(array[j][0],array[j][1],array[k][0],array[k][1]);
                tmp.second.first = j;
                tmp.second.second = k;
                distlist.push_back(tmp);
            }
        }
        sort(distlist.begin(), distlist.end());
        for(j=0;j<P;j++){
            root[j]=j;
            _rank[j]=0;
        }
        for(j=0;j<(unsigned int)distlist.size();j++){
            _union(distlist[j].second.first, distlist[j].second.second);
            if(cnt == S){
                cout<<distlist[j].first<<endl;
                break;
            }
        }
        distlist.clear();
    }
    
    return 0;
}
