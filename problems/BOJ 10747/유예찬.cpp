// baekjoon 10747 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_L = 1000001;

char str[MAX_L], com[MAX_L], ans[MAX_L];
int pi[MAX_L], a[MAX_L];

void getpi() {
	for (int i=0, j=-1; com[i]; ) {
		if (j < 0 || com[i] == com[j])
			pi[++i]	= ++j;
		else j = pi[j];
	}
}

int main() {
	memset(pi, -1, sizeof(pi));
	scanf("%s%s", str, com);
	int pos=0;
	getpi();
	for (int i=0, j=0; str[i];) {
		if (j < 0 || str[i] == com[j]) {
			ans[pos] = str[i];
			pos++, i++;
			a[pos] = j+1;
			j++;
			if (!com[j]) {
				pos -= j;
				j = a[pos];
			}
		}
		else {
			j = pi[j];
		}
	}
	ans[pos]='\0';
	puts(ans);
	return 0;
}