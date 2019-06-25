#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first)return a.second < b.second;
    else return a.first > b.first;
}

int main() {
    
    int N,deadline,noodle,itr;
    vector<pair<int,int>> list;
    int *ans_cnt;
    long answer=0;
    cin>>N;
    ans_cnt = new int[N+1];
    fill_n(ans_cnt, N+1, 0);
    for(int i=0;i<N;i++){
        cin>>deadline>>noodle;
        list.push_back(make_pair(noodle,deadline));
    }
    sort(list.begin(),list.end(),compare);
    for(int i=0;i<list.size();i++){
        itr = list[i].second;
        if(ans_cnt[itr] == 2)continue;
        while(ans_cnt[itr] != 0)itr --;
        if(itr == 0){
            ans_cnt[list[i].second] = 2;
            continue;
        }
        ans_cnt[itr]++;
        answer += list[i].first;
    }
    cout<<answer;
    return 0;
}
