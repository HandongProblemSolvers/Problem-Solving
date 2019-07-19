//BOJ3687 성냥개비
#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, di, mo, mi[7], one[7], mini;

int main(){
    scanf("%d", &T);
    one[2] = 1, one[3] = 7, one[4] = 4, one[5] = 2, one[6] = 6;
    mi[0] = 8, mi[1] = 10, mi[2] = 18, mi[3] = 200, mi[4] = 20, mi[5] = 28, mi[6] = 68;
    while(T--){
        scanf("%d", &n);
        di = n/7;
        mo = n%7;
        if(!di) printf("%d", one[mo]);
        else if(di == 1) {
            if(mo == 3) printf("22");
            else printf("%d", mi[mo]);
        }
        else{
            mini = mi[mo];
            printf("%d", mini);
            if(mo == 3){
                for(int i = 2; i < di; i++)
                    printf("8");
            }
            else{
                for(int i = 1; i < di; i++)
                    printf("8");
            }
        }
        printf(" ");

        if(n%2 == 1) printf("7");
        else printf("1");
        for(int i = 1; i < n/2; i++) printf("1");
        printf("\n");
    }

    return 0;
}