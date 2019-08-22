//  Created by Hanyoung Yoo on 22/08/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.

#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
#define INF 2e9

int N,M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    vector<pair<int,int>> graph[N+1];
    for (int i=0;i<M;i++){
        int a,b,d;
        cin>>a>>b>>d;
        graph[a-1].push_back(make_pair(b-1, d));
        graph[b-1].push_back(make_pair(a-1, d));
    }
    int dist[N+1];
    fill(dist,dist+sizeof(dist),INF);
    priority_queue<pair<int,int>,deque<pair<int, int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    // dijkstra for fox
    while(!pq.empty()){
        int here = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i].first;
            int next_time = graph[here][i].second;
            
            if(dist[next] > dist[here] + next_time){
                dist[next] = dist[here] + next_time;
                pq.push(make_pair(dist[next],next));
            }
        }
    }
    
    int dist_wolf[N+1][2]; // current_status == 0 or current_status == 1
    for(int i=0;i<=N+1;i++){
        dist_wolf[i][0] = INF;
        dist_wolf[i][1] = INF;
    }
    
    priority_queue<pair<int,int>,deque<pair<int, int>>,greater<pair<int,int>>> pq_wolf;
    pq_wolf.push(make_pair(0, 0));
    dist_wolf[0][1] = 0;
    // dijkstra for wolf
    while(!pq_wolf.empty()){
        int here = pq_wolf.top().second;
        pq_wolf.pop();
        for(int i = 0; i < graph[here].size(); i++){
            int next = graph[here][i].first;
            int next_time_fine = graph[here][i].second / 2;
            int next_time_exhausted = graph[here][i].second * 2;
            if(dist_wolf[here][1] != INF){
                if(dist_wolf[next][0] > dist_wolf[here][1] + next_time_fine){
                    dist_wolf[next][0] = dist_wolf[here][1] + next_time_fine;
                    pq_wolf.push(make_pair(dist_wolf[next][0], next));
                }
            }
            if(dist_wolf[here][0] != INF){
                if(dist_wolf[next][1] > dist_wolf[here][0] + next_time_exhausted){
                    dist_wolf[next][1] = dist_wolf[here][0] + next_time_exhausted;
                    pq_wolf.push(make_pair(dist_wolf[next][1], next));
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist_wolf[i][0] > dist_wolf[i][1])
            dist_wolf[i][0] = dist_wolf[i][1];
    }
    int result = 0;
    
    for (int i=0;i<N;i++){
        if(dist[i] < dist_wolf[i][0])
            result ++;
    }
    cout<<result;
    return 0;
}
