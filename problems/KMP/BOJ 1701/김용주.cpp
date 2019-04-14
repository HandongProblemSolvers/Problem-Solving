//BOJ1701 Cubeditor
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_S 5001

char S[MAX_S];
int fail[MAX_S], s_len, ans;

int main() {
	cin >> S;
	s_len = strlen(S);

	for (int k = 0; k < s_len; k++) {
		memset(fail, 0, sizeof(fail));
		fail[k] = k;
		for (int i = 1 + k, j = k; i < s_len; i++) {
			while (j > k && S[i] != S[j]) j = fail[j -1];
			if (S[i] == S[j]) fail[i] = ++j;
			else fail[i] = k;
			ans = max(ans, j - k);
		}
	}

	cout << ans;
	return 0;
}