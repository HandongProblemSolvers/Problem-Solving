// baekjoon 3042 yechan
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> P;

char board[101];
int N, i, j, k, alphaNum;
long long ret;
P alpha[27];

inline bool check(P &a, P &b, P &c) {
    return (a.second - b.second)*(b.first - c.first) == (b.second - c.second)*(a.first - b.first);
}

int main() {
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%s", board);
        for (j=0; j<N; j++)
            if (board[j] != '.')
                alpha[alphaNum++] = {i,j};
    }

    for (i=0; i<alphaNum; i++)
        for (j=i+1; j<alphaNum; j++)
            for (k=j+1; k<alphaNum; k++)
                ret += check(alpha[i], alpha[j], alpha[k])

    printf("%lld\n", ret);
    return 0;
}