//BOJ_2579


#include <cstdio>

int N;
int storeM[301];


int max(int a, int b){
    return (a > b) ? a: b;
}

int main() {
    
    scanf("%d", &N);
    int step[N];
    
    for(int i=0; i<N; i++){
        scanf("%d", &step[i]);
    }
    
    //before start, store the three value firstly. (these dont have previous values)
    storeM[0]=step[0];
    storeM[1]=max(step[0]+step[1], step[1]);
    storeM[2]=max(step[0]+step[2], step[1]+step[2]);
    
    //compare two situations
    for(int i=3; i<N; i++){
        storeM[i]=max(storeM[i-2]+step[i], storeM[i-3]+step[i-1]+step[i]);
    }
    
    printf("%d", storeM[N-1]);
    
    return 0;
}
