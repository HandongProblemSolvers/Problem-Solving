#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

string s;
int N;

int main(void)
{
  cin >> s;
  if(s.find("0")!=string::npos){
    sort(s.begin(),s.end(),greater<int>());
    int sum = 0;
    for(int i=0; i<s.length()-1; i++) sum += s[i]-'0';
    if(sum%3) puts("-1");
    else for(char c : s) printf("%c",c);
  } else {
    puts("-1");
  }
  return 0;
}
