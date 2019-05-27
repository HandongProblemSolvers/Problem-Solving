//BOJ3042 트리플렛
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 101
typedef pair<int, int> P;

int N;
vector<P> arr;

bool incli(P a, P b, P c){
    int v1 = (a.first - b.first)*(b.second - c.second);
    int v2 = (b.first - c.first)*(a.second - b.second);
    if(v1 == v2) return true;
    return false;
}

int main(){
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++){
        char ch;
        for(int j = 0; j < N; j++){
            scanf("%c", &ch);
            if(ch >= 'A' && ch <= 'Z') arr.push_back({i,j});
        }
        scanf("%c", &ch);        
    }

    int ans = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            for(int k = j+1; k < arr.size(); k++){
                if(incli(arr[i], arr[j], arr[k])) ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}