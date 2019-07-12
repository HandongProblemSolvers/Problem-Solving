//BOJ1972 놀라운문자열
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[26][26];
char s[81];
bool visit[26][26], chk;

int main(){
    while(1){
        scanf("%s", s);
        if(s[0] == '*') break;
        int len = strlen(s);
        chk = true;
        for(int i = 1; i < len; i++){
            memset(visit, 0, sizeof(visit));
            for(int j = 0, k = i; k < len; j++, k++){
                int a = s[j] - 65;
                int b = s[k] - 65;
                if(visit[a][b]){
                    printf("%s is NOT surprising.\n", s);
                    chk = false;
                    i = len;
                    break;
                }
                visit[a][b] = true;
            }
        }
        if(chk) printf("%s is surprising.\n", s);
    }

    return 0;
}