#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef struct node{
    pair<int, int> prev;
    pair<int, int> next;
    int weight;
}Node;

int main() {
    ios::sync_with_stdio(false);
    const int inf = 987654321;
    int W,H,G,E;
    int X,Y,X1,Y1,X2,Y2,t;
    int negative_check = 0;
    for(;;){
        cin>>W>>H;
        if(W == 0 && H == 0)return 0;
        int* vertex_array;
        vertex_array = new int[W*H];
        vector<node> node_list;
        
        cin>>G;
        for(int i=0;i<G;i++){
            cin>>X>>Y;
            vertex_array[X+Y*W] = inf;
            // if vertex_array = inf, tomb
        }
        node tmp;
        for(int i=0;i<W*H-1;i++){
            if(vertex_array[i] == inf)continue;
            //current loc = (i%W , i/W)
            // right : i%W+1, i/W if(i%W == W-1)continue;
            tmp.prev.first = i%W;
            tmp.prev.second = i/W;
            tmp.weight = 1;
            if(i % W != W-1){
                if(vertex_array[i+1] != inf){
                    tmp.next.first = i%W+1;
                    tmp.next.second = i/W;
                    node_list.push_back(tmp);
                }
            }
            // left
            if(i % W != 0){
                if(vertex_array[i-1] != inf){
                    tmp.next.first = i%W-1;
                    tmp.next.second = i/W;
                    node_list.push_back(tmp);
                }
            }
            // up : i%W, i/W+1 if(i/W == H-1)continue;
            if(i/W != H-1){
                if(vertex_array[i+W] != inf){
                    tmp.next.first = i%W;
                    tmp.next.second = i/W+1;
                    node_list.push_back(tmp);
                }
            }
            // down
            if(i/W != 0){
                if(vertex_array[i-W] != inf){
                    tmp.next.first = i%W;
                    tmp.next.second = i/W-1;
                    node_list.push_back(tmp);
                }
            }
        }
        cin>>E;
        for(int i=0;i<E;i++){
            cin>>X1>>Y1>>X2>>Y2>>t;
            tmp.prev.first = X1;
            tmp.prev.second = Y1;
            tmp.next.first = X2;
            tmp.next.second = Y2;
            tmp.weight = t;
            if(X1 == X2 && Y1 == Y2 && t<0){
                negative_check = 1;
            }
            node_list.push_back(tmp);
        }
        // hole node update
        for(int i=1;i<W*H;i++){
            vertex_array[i]=inf;
        }
        vertex_array[0]=0;
        //relaxation
        for(int j=0;j<W*H-G-1;j++){
            for(int i=0;i<node_list.size();i++){
                if(vertex_array[node_list[i].next.first+node_list[i].next.second*W] >
                   vertex_array[node_list[i].prev.first+node_list[i].prev.second*W] + node_list[i].weight){
                    vertex_array[node_list[i].next.first+node_list[i].next.second*W] = vertex_array[node_list[i].prev.first+node_list[i].prev.second*W] + node_list[i].weight;
                }
            }
        }
        //another relaxation
        for(int i=0;i<node_list.size();i++){
            if(vertex_array[node_list[i].next.first+node_list[i].next.second*W] >
               vertex_array[node_list[i].prev.first+node_list[i].prev.second*W] + node_list[i].weight){
                negative_check = 1;
                break;
            }
        }
        if(negative_check == 1){
            cout<<"Never"<<endl;
            negative_check = 0;
            continue;
        }
        else{
            if(vertex_array[W*H-1] == inf){
                cout<< "Impossible"<<endl;
            }
            else{
                cout<<vertex_array[W*H-1]<<endl;
            }
        }
        
        delete [] vertex_array;
        node_list.clear();
    }
    return 0;
}
