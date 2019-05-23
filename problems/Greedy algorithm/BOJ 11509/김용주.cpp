//BOJ11509 풍선 맞추기
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000001

int n, h, arr[MAX_N], ans;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &h);
        if(!arr[h]){
            ans++;
        }
        arr[h-1]++;
    }
    printf("%d", ans);

    return 0;
}