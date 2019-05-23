#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int parent[501];
int N, S, P, x, y, c;
double result;
vector <pair <int, int> > cordi;
pair <int, int> tmp;

double getDistance(int x1, int y1, int x2, int y2) {
    double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return dist;
}

void init() {
    for (int i = 1; i <= y; i++)
        parent[i] = i;
}

int find(int x) {
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    c--;
    parent[x] = y;
}


int main() {
    scanf("%d" , &N);
    while (N--) {
        scanf("%d %d", &S, &P);
        init();
        result = 0.0;

        for (int i = 0; i < P; i++) {
            scanf("%d %d", &x, &y);
            cordi.push_back(make_pair(x, y));
        }

        c = y - x;
        priority_queue<pair<double, pair<int, int> > > pq;


        for (int i = 1; i < P; i++) {
            for (int j = 1; j < P; j++) {
                pq.push({ -getDistance(cordi[i].first, cordi[i].second, cordi[j].first, cordi[j].second), {i,j} });
            }
        }

        while (c) {
            result = -pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
            merge(x, y);
        }
        printf("%.2lf\n", result);


    }
    return 0;
}
