// baekjoon 1972 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_LEN=88;
const int MAX_ALPHA=26;

int pos1, pos2;
char S[MAX_LEN];
bool visited[MAX_ALPHA][MAX_ALPHA];

int main() {
	while (1) {
		scanf("%s", S);
		if (S[0] == '*') break;
		int slen = strlen(S);
		bool check = true;
		for (int d=1; d<slen; d++) {
			memset(visited, 0, sizeof(visited));
			for (int start=0; start<slen-d; start++) {
				pos1 = S[start]-'A';
				pos2 = S[start+d]-'A';
				if (visited[pos1][pos2]) check = false;
				visited[pos1][pos2]=true;
			}
			if (!check) break;
		}
		if (check) printf("%s is surprising.\n", S);
		else printf("%s is NOT surprising.\n", S);
	}
	return 0;
}