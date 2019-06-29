//  boj17074
//  Created by Hanyoung Yoo on 26/06/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.

#include <iostream>
using namespace std;
int main() {
    int N,check_split = 0;
    int cnt_split=0;
    int *a;
    cin>>N;
    a = new int[N];
    for(int i=0;i<N;i++)cin>>a[i];
    if(N==2){
        cout<<'2'<<'\n';
        return 0;
    }
    for(int i=0;i<N-1;i++){
        if(a[i] > a[i+1]){
            if(check_split == 1){ // split occurs 2 times
                cout<<'0'<<'\n';
                return 0;
            }
            check_split = 1;
            if(i == 0){
                if(a[i] <= a[i+2])cnt_split = 2;
                else cnt_split = 1; // a[i]>a[i+2]
            }
            else if(i == N-2){
                if(a[i-1] <= a[i+1])cnt_split = 2;
                else cnt_split = 1; // a[i-1] > a[i+1]
            }
            else {
                if(a[i-1] <= a[i+1])cnt_split++;
                if(a[i] <= a[i+2])cnt_split++;
            }
        }
    }
    if(check_split == 1){
        cout<<cnt_split<<'\n';
    }
    else cout<<N<<'\n';
    return 0;
}
