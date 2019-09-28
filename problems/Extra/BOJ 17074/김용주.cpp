//BOJ17074 정렬
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100003
const int INF = 1e9;
int N, arr[MAX_N], cnt, loc, ans;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    arr[N+1] = INF;
    for(int i = 1; i < N; i++){
        if(arr[i] > arr[i+1]) cnt++;
        loc = i;
    }
    
    if(cnt == 0) printf("%d", N);
    else if(cnt > 1) printf("0");
    else{
        if(arr[loc-1] <= arr[loc+1]) ans++;
        if(arr[loc] <= arr[loc+2]) ans++;
        printf("%d", ans);
    }
    return 0;
}