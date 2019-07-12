//BOJ_1972

#include <string.h>
#include <stdio.h>

using namespace std;

char str[81];
int s1, s2, length;
bool visit[26][26], check;

int main() {

    while(true){
        scanf("%s", str);
        int length=strlen(str);
        if(str[0] == '*')
            break;
        check=true;
        for(int i=1; i<length; i++){
            memset(visit, 0, sizeof(visit));
            for(int j=0; j<length-i; j++){
                s1 = str[j]-'A';
                s2 = str[j+i]-'A';
                if(visit[s1][s2])
                    check=false;
                visit[s1][s2]=true;
            }
            if(!check){
                printf("%s is NOT surprising.\n", str);
                break;
            }
        }
        if(check){
            printf("%s is surprising.\n", str);
        }
    }
    return 0;
}
