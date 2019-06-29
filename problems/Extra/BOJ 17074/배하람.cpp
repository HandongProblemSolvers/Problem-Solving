#include <cstdio>

int N;
int input[100001];

int main(void)
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&input[i]);

    int blockNum = 0, blockIndex = 0, ans = 0;
    for(int i=1; i<N; i++){
        if(input[i] > input[i+1]) {
            if(blockIndex) {
                return printf("0"),0;
                break;
            }
            blockNum++;
            blockIndex = i;
        }
    }
    if(blockNum == 0) return printf("%d\n",N),0;
    ans += (blockIndex==1 || input[blockIndex-1]<=input[blockIndex+1]);
    ans += (blockIndex==N-1 || input[blockIndex]<=input[blockIndex+2]);
    printf("%d\n",ans);
    return 0;
}