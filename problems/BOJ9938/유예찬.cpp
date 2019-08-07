// baekjoon 9938 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=300001;

int N, L, root[MAX_N], slot[MAX_N];

int find(int x)
{
	if (root[x] < 0) return x;
	return root[x] = find(root[x]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (slot[a] && slot[b]) return false;

	if (slot[a] == 0) slot[a] = 1;
	else slot[b] = 1;

	if (a == b) return true;
	root[a] = b;
	return true;
}


int main()
{
	fill(root, root+MAX_N, -1);
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		if (merge(A, B)) printf("LADICA\n");
		else printf("SMECE\n");
	}
	return 0;
}