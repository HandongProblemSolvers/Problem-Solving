#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <iostream>
using namespace std;
#define MN 105
#define MM 10005
string no = "Poor KCM";
struct data {
    int v, c, d;
    bool operator < (const data &d1) const {
        return d > d1.d;
    }
} dat, now, up;
int N, M, K, res;
vector <data> a[MN];
int d[MN][MM];
int main() {
    int runs;
    for (scanf("%d", &runs); runs--;) {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1; i <= N; i++) a[i].clear();
        for (int i = 1; i <= K; i++) {
            int v1, v2, C, D;
            scanf("%d%d%d%d", &v1, &v2, &C, &D);
            dat.v = v2; dat.c = C; dat.d = D;
            a[v1].push_back(dat);
        }
        memset(d, -1, sizeof(d));
        res = 0;
        priority_queue <data> Q;
        dat.v = 1; dat.c = 0; dat.d = 0;
        Q.push(dat);
        d[1][0] = 0;
        while (!Q.empty()) {
            now = Q.top(); Q.pop();
            if (d[now.v][now.c] < now.d) continue;
            d[now.v][now.c] = now.d;
            for (int i = 0; i < a[now.v].size(); i++) {
                dat = a[now.v][i];
                if (dat.c + now.c > M) continue;
                if (d[dat.v][now.c + dat.c] == -1 || d[dat.v][now.c + dat.c] > now.d + dat.d) {
                    d[dat.v][now.c + dat.c] = now.d + dat.d;
                    up.v = dat.v;
                    up.c = now.c + dat.c;
                    up.d = now.d + dat.d;
                    Q.push(up);
                }
            }
        }
        res = 2147483647;
        for (int i = 0; i <= M; i++) if (d[N][i] != -1 && res > d[N][i]) res = d[N][i];
        if (res != 2147483647) printf("%d\n", res);
        else cout << no << "\n";
    }
}
