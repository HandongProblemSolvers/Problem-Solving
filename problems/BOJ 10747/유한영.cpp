#include<cstdio>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s,t;
void kmp() {
	int i, j=0;
	int M;
	vector<int> pi((int)t.size(), 0);
	for (i = 1; i < (int)t.size(); i++) {
		while (j > 0 && pi[i] != pi[j - 1]) {
			j = pi[j - 1];
		}
		if (t[j] == t[i]) {
			pi[i] = ++j;
		}
	}
	M = (int)t.size();
	for (i = 0; i < (int)s.size(); i++) {
		while (j > 0 && s[i] != t[j]) {
			j = pi[j - 1];
		}
		if (s[i] == t[j]) {
			if (j == M - 1) {
				s.erase(s.begin()+(i - (t.size()-1)), s.begin()+i+1);
				if(i>(2*t.size()+1))i = i - (2*t.size()+1);
				else i = -1;
				j = 0;
			}
			else {
				j++;
			}
		}
	}
	return;
}
int main() {
	cin >> s;
	cin >> t;
	kmp();
	cout << s;
	return 0;
}