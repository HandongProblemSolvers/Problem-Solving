// baekjoon 3698 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=10001;

char sentence[1001], word[MAX_N][101];
int T, N, L, wordlen[MAX_N], dp[1001], trace[1001];

int checkWord(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	if (here == L) return 1;

	ret = 0;
	for (int i=0; i<N; i++) {
		if ((here + wordlen[i] > L) || (word[i][0] != sentence[here]) || (word[i][wordlen[i]-1] != sentence[here + wordlen[i]-1])) continue;
		int count[26] = {0};
		for (int j=1; j<wordlen[i]-1; j++) {
			count[word[i][j] - 'a']++;
			count[sentence[here+j] - 'a']--;
		}

		bool check = false;
		for (int j=0; j<26; j++) {
			if (count[j]) q{
				check=true;
				break;
			}
		}
		if (check) continue;
		if (!checkWord(here+wordlen[i])) continue;
		ret += checkWord(here + wordlen[i]);
		trace[here] = i;
	}
	return ret;
}

void printword(int here) {
	if (here == L) {
		puts("");
		return;
	}
	printf("%s ", word[trace[here]]);
	printword(here + wordlen[trace[here]]);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof(dp));
		scanf("%s", sentence);
		scanf("%d", &N);
		L = strlen(sentence);
		for (int i=0; i<N; i++) {
			scanf("%s", word[i]);
			wordlen[i] = strlen(word[i]);
		}
		int ans = checkWord(0);
		if (ans == 0) puts("impossible");
		else if (ans == 1) printword(0);
		else puts("ambiguous");
	}
	return 0;
}