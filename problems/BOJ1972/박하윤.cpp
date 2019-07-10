// 문자열_놀라운 문자열_197
#include <cstdio>
#include <cstring>
using namespace std;

char str[81];
bool visited[26][26], check;

int main(){
  while(1){
    scanf("%s", str);
    if(str[0] == '*') break;
    int len = strlen(str);
    check = false;
    for(int i = 1; i < len; i++){
      memset(visited, 0, sizeof(visited));
      for(int j = 0; j < len-i; j++){
        int a = str[j] - 65;
        int b = str[j+i] - 65;
        if(visited[a][b]){
          check = true;
          break;
        }
        visited[a][b] = true;
      }
      if(check) {
        printf("%s is NOT surprising.\n", str);
        break;
      }
    }
    if(!check) printf("%s is surprising.\n", str);
  }
  return 0;
}
