//BOJ1395 스위치
#include <cstdio>
#include <algorithm>
#define MAX_N 100001
using namespace std;
int N, M, O, S, T, arr[4 * MAX_N], lazy[4 * MAX_N];

void propagation(int node, int left, int right) {
    if (!lazy[node]) return;
    arr[node] = (right - left + 1) - arr[node];

    if (left != right) {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
    }

    lazy[node] = 0;
}

int update(int lo, int hi, int node, int left, int right) {
    propagation(node, left, right);
    if (right < lo || hi < left) return arr[node];
    if (lo <= left && right <= hi) {
        lazy[node] = !lazy[node];
        propagation(node, left, right);
        return arr[node];
    }

    int mid = (left + right) >> 1;
    return arr[node] = update(lo, hi, node * 2, left, mid) + update(lo, hi, node * 2 + 1, mid + 1, right);
}

int sum(int lo, int hi, int node, int left, int right) {
    propagation(node, left, right);
    if (right < lo || hi < left) return 0;
    if (lo <= left && right <= hi) return arr[node];

    int mid = (left + right) >> 1;
    int l = sum(lo, hi, node * 2, left, mid);
    int r = sum(lo, hi, node * 2 + 1, mid + 1, right);
    return l + r;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &O, &S, &T);
        if (O) printf("%d\n", sum(S, T, 1, 1, N));
        else update(S, T, 1, 1, N);
    }
    return 0;
}