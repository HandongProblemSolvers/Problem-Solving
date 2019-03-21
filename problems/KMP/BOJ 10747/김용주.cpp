//BOJ10747 Consoring
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_S 1000001

char S[MAX_S], T[MAX_S], ans[MAX_S];
int fail[MAX_S], cnt[MAX_S], s_len, t_len, idx;

int main() {
	cin >> S >> T;
	s_len = strlen(S);
	t_len = strlen(T);
	//실패함수.
	for (int i = 1, j = 0; i < t_len; i++) {
		while (j > 0 && T[i] != T[j]) j = fail[j];
		if (T[i] == T[j]) fail[i] = ++j;
	}

	for(int i = 0, j = 0; i < s_len; i++){
		while (S[i] != T[j] && j > 0) j = fail[j - 1];
		if (S[i] == T[j]) {
			ans[idx] = S[i]; //stack과 유사한 역할
			idx++;
			cnt[idx] = ++j;
			if (j == t_len) {
				idx -= j;
				j = cnt[idx];
			}
		}
		else {
			ans[idx] = S[i];
			idx++;
		}
	}
	ans[idx] = '\0';
	cout << ans;
	return 0;
}