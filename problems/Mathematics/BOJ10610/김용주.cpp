#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX_N 100001
typedef long long ll;

char N[MAX_N];
ll sum;
bool chk;

int partition(int p, int r){
    int x = N[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(N[j] > x){
            i++;
            swap(N[j], N[i]);
        }
    }
    swap(N[r], N[i+1]);
    return i+1;
}

void quicksort(int p, int r){
    if(p < r){
        int q = partition(p, r);
        quicksort(p, q-1);
        quicksort(q+1, r);
    }
}

int main(){
    scanf("%s", N);
    int len = strlen(N);

    for(int i = 0; i < len; i++){
        if(N[i] == '0') chk = true;
        else sum += N[i] - '0';
    }
    if(sum % 3) chk = false;

    if(chk) {
        quicksort(0, len-1);
        printf("%s", N);
    }
    else printf("-1");

    return 0;
}