#include <cstdio>
char b[101][101],c[1024],n,x,y,d,g;
int s;

int main(void)
{
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&x,&y,&d,&g);
        c[s]=d;
        b[y][x]=1;
        b[y+=d%2?(d==1?-1:1):0][x+=d%2?0:(!d?1:-1)]=1;
        for(int i=0; i<g; i++){
            for(int j=s; j>=0; j--){
                x+=c[j]%2?(c[j]==1?-1:1):0;
                y+=c[j]%2?0:(!c[j]?-1:1);
                b[y][x]=1;
                c[++s]=(c[j]+1)%4;
            }
        }
        s=0;
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(b[i][j]&b[i+1][j]&b[i][j+1]&b[i+1][j+1]){
                s++;
            }
        }
    }
    printf("%d\n",s);
    return 0;
}