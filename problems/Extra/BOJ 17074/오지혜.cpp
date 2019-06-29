//BOJ_17074


#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    int *arr = new int[N];
    int cnt=0;
    int mark=0;
    int n=0;
    
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
        
        if(i==0){
            continue;
        }
        else{
            //marking in the case of decreasing
            if(arr[i-1]>arr[i]){
                cnt++;
                mark=i-1;
            }
        }
    }
    
    //case 1: No decrease
    if(cnt==0){
        cout << N;
    }
    //case 2: One decrease
    else if(cnt==1){
        if(arr[mark-1]<=arr[mark+1])
            n++;
        if(mark+2<=N-1 && arr[mark]<=arr[mark+2])
            n++;
        if(mark+2>N-1)
            n++;
        cout << n;
    }
    //case 3: Over one decrease
    else{
        cout << 0;
    }

    
    return 0;
}


