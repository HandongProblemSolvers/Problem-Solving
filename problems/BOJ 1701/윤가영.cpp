#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

int pi[5001][5001];
int max;
char str[5001];

int main(){
    scanf("%d", str);
    for(int i=0; i<str.length(); i++){
        string temp = str.substr(i, str.length());
        int j=0;
        for(int k=1; k<temp.size(); k++){
            while(j >0 && temp[k]!= temp[j]){
                j=pi[i][k-1];
            }
            if(temp[k]==temp[j]){
                j++;
                pi[i][k]=j;
            }
        }

        for(int ii=0; ii<temp.size();ii++){
            if(pi[i][ii] > max) max = pi[i][ii];
        }
    }

    printf("%d", max);
}