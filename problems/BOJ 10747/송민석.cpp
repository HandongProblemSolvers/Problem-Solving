#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> getPi(string &s) {
	int length = s.length();
	int i = 0, count = 0;

	vector<int> pi(1, 0);
	for (i = 1; i < length; i++) {
		if (s[count] == s[i]) {
			count++;
		}
		else {
			if (count != 0) {
				count = pi[count - 1];
				i--;
				continue;
			}
		}
		pi.push_back(count);
	}
	return pi;
}

void modified_kmp(string &s, string &t) {
	stack<pair<int, int> > j_stack;
	int i = 0, j = 0;

	vector<int> pi = getPi(t);
	for (i = 0; i < s.length(); i++) {
		if (s[i] == t[j]) {
			j++;
			if (j == t.length()) {
				s.erase(i - j + 1, j);
				if (j_stack.empty()) {
					i -= j;
					j = 0;
				}
				else {
					pair<int, int> temp = j_stack.top();
					j_stack.pop();
					i = temp.first;
					j = temp.second;
				}
			}
		}
		else {
			if (j != 0) {
				j_stack.push(make_pair(i - 1, j));
				j = pi[j - 1];
				i--;
			}
			else {
				while(!j_stack.empty())
					j_stack.pop();
			}
		}
	}
}

int main() {
	string S, T;

	getline(cin, S);
	getline(cin, T);

	modified_kmp(S, T);
	cout << S << endl;

	return 0;
}
