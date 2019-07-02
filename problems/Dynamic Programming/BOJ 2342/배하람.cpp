#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int in;
vector<int> input;
int cache[100000][5][5];

int danceStrength(int from, int to)
{
    if(from == 0) return 2;
    if(from == to) return 1;
    if((from+to)%2 == 0) return 4;
    return 3;
}

int danceRecursive(int index, int left, int right)
{
    if(index == input.size()-1) return 0;
    if(left == right && left != 0) return (int)2e9;
    int &ret = cache[index][left][right];
    if(ret != -1) return ret;
    int ls = danceStrength(left,input[index]);
    int rs = danceStrength(right,input[index]);
    return ret = min(danceRecursive(index+1,input[index],right)+ls,
        danceRecursive(index+1,left,input[index])+rs);
}

int main(void)
{   
    while(true) {
        scanf("%d",&in);
        input.push_back(in);
        if(!in) break;
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",danceRecursive(0,0,0));
    return 0;
}