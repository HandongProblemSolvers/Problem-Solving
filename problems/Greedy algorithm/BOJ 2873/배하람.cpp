#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int r,c;
int a[1001][1001];

int main(void)
{
    scanf("%d%d",&r,&c);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf("%d",&a[i][j]);
        }
    }

    if(c%2==1){
        for(int i=1; i<=c; i++){
            if(i%2==1){
                for(int j=1; j<=r-1; j++) printf("D");
                if(i!=c) printf("R");
            } else{
                for(int j=1; j<=r-1; j++) printf("U");
                printf("R");
            }
        }
    }

    else if(r%2==1){
        for(int i=1; i<=r; i++){
            if(i%2==1){
                for(int j=1; j<=c-1; j++) printf("R");
                if(i!=r) printf("D");
            } else{
                for(int j=1; j<=c-1; j++) printf("L");
                printf("D");
            }
        }
    }

    else {
        int minx = 1, miny = 2;
        int minv = 2e9;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(i==1 && j==1) continue;
                if(i==r && j==c) continue;
                if((i+j)%2!=0 && minv > a[i][j]){
                    minv = a[i][j];
                    minx = i;
                    miny = j;
                }
            }
        }

        int ax = 1, ay = 1, bx = r, by = c;
        string s1,s2;

        while(bx-ax>1){
            if((ax-1)/2 < (minx-1)/2){
                for(int i=1; i<=c-1; i++) s1+='R'; s1+='D';
                for(int i=1; i<=c-1; i++) s1+='L'; s1+='D';
                ax += 2;
            }
            if((minx-1)/2 < (bx-1)/2){
                for(int i=1; i<=c-1; i++) s2+='R'; s2+='D';
                for(int i=1; i<=c-1; i++) s2+='L'; s2+='D';
                bx -= 2;
            }
        }

        while(by-ay>1){
            if((ay-1)/2 < (miny-1)/2){
                s1+='D'; s1+='R';
                s1+='U'; s1+='R';
                ay += 2;
            }
            if((miny-1)/2 < (by-1)/2){
                s2+='D'; s2+='R';
                s2+='U'; s2+='R';
                by -= 2;
            }
        }
        if(ay==miny) {
            s1+='R';
            s1+='D';
        } else {
            s1+='D';
            s1+='R';
        }
        reverse(s2.begin(),s2.end());
        s1+=s2;
        cout << s1;
    }

    return 0;
}