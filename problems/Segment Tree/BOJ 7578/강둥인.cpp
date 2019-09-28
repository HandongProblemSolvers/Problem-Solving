#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

vector<ll> tree, arr;
int h[1000010];


void update(int node, int start, int end, int index, int diff) {
    if (start > index || index > end)
        return;

    tree[node] += diff;

    if (start ^ end) {
        update(node*2, start, (start + end) / 2, index, diff);
        update(node*2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2 + 1, (start+end)/2 + 1, end, left, right);
}

// ll init(int node, int start, int end) {
//     // leaf node
//     if (start == end)
//         return tree[node] = arr[start];

//     int mid = (start + end) / 2;
//     return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
// }


int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int N;
    cin >> N;

    arr = vector<ll>(N + 10);
	tree = vector<ll>(4 * N + 40);
    
    
    for (int i = 1; i <= N; i++) {
        ll tmp; 
        cin >> tmp;
		h[tmp] = i;
    }
   
    for (int i = 1; i <= N; i++) {
        ll tmp; 
        cin >> tmp;
		arr[i] = h[tmp];
    }

    ll answer = 0;

    for(int i = 1; i <= N; i++){
		int j = arr[i];
		answer += sum(1, 1, N, j+1, N);
		update(1, 1, N, j, 1);
	}

    cout << answer << endl;
    return 0;
}