// Greedy_30_10610

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string N;
vector<int> digits;
int sum;

int main(){
  cin >> N;
  for(int i = 0; i < N.length(); i++)
    digits.push_back(N[i] - '0');

  sort(digits.begin(), digits.end(), greater<int>());

  int C = digits.size()-1;
  for(int i = 0; i < C; i++)
    sum += digits[i];

  if(sum % 3 == 0 && digits[C] == 0) {
      for(int i = 0; i < digits.size(); i++)
        cout << digits[i];
  } else cout << "-1";

  return 0;
}
