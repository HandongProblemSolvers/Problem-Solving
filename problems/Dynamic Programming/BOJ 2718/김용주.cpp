//BOJ2718 타일 채우기(4xn 타일링)
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, dp[10001][5];

int tile(int n, int state){
    if(n < 0) return 0;
    int &ret = dp[n][state];
    if(ret != -1) return ret;

    switch(state){
        //다 채워진 상태
        case 0:
            ret = tile(n-2, 0) + tile(n-1, 0) + tile(n-1, 1) + tile(n-1, 2) + tile(n-1, 3);
            break;
        
        //위에 2블럭만 채워진 상태
        case 1:
            ret = tile(n-1, 2) + tile(n-1, 0);
            break;

        //아래 2블럭만 채워진 상태
        case 2:
            ret = tile(n-1, 1) + tile(n-1, 0);
            break;

        //가운데 2블럭만 채워진 상태
        case 3:
            ret = tile(n-1, 4) + tile(n-1, 0);
            break;

        //양 끝 블럭만 채워진 상태, 이 경우 다음에는 가운데 2개가 채워지면 양 끝 블록이 비는데
        //이 블럭을 다음 단계로 넘어가지 않는 이상 채울 방법이 없음.
        case 4:
            ret = tile(n-1, 3);
    }

    return ret;
}

int main(){
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i < 5; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;

    while(T--){
        scanf("%d", &N);
        printf("%d\n", tile(N, 0));
    }

    return 0;
}