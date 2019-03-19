#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];
string tmp;

int main() {
	cin>>tmp;
    string temp ="0" + tmp;
    int size = tmp.size();
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            if(temp[j]==temp[size-i+1]) dp[i][j] = dp[i-1][j-1]+1;
            else if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i][j-1];
        }
    }

    cout<<size + size - dp[size][size];
}