//BOJ_1781

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    typedef pair<int, int> nInfor;
    nInfor cupNoodle[200000];
    priority_queue<int, vector<int>, greater<int>> queue;
    int N=0, time=0, result=0;
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        cin>>cupNoodle[i].first>>cupNoodle[i].second;
    
    //sort to store in order of deadline
    sort(cupNoodle, cupNoodle+N);

    for(int j=0; j<N; j++){
        time=cupNoodle[j].first;
        queue.push(cupNoodle[j].second);
        
        //when the time is over, pop lower thing(the number of cupnoodle)
        while(time<queue.size())
            queue.pop();
    }
    
    while(!queue.empty()){
        result+=queue.top();
        queue.pop();
    }
    
    cout<<result;
    
    
    return 0;
}
