// baekjoon 2143 yechan [Optimize, Two-pointer 60ms]
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_NN= (MAX_N*(MAX_N+1))/2;
int T, N, M, A[MAX_N], B[MAX_N], tmp, sA, sB, pA, pB, cntA, cntB;
int seqA[MAX_NN], seqB[MAX_NN];

int main() {
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &A[i]);
		A[i]+=A[i-1];
	}

	for (int i=1; i<=N; i++)
		for (int j=i; j<=N; j++, sA++)
			seqA[sA] = A[j]-A[i-1];

	scanf("%d", &M);
	for (int i=1; i<=M; i++) {
		scanf("%d", &B[i]);
		B[i]+=B[i-1];
	}

	for (int i=1; i<=M; i++)
		for (int j=i; j<=M; j++, sB++)
			seqB[sB] = B[j]-B[i-1];

	sort(seqA, seqA+sA);
	sort(seqB, seqB+sB);

	pA = 0;
	pB = sB-1;
	long long ret = 0;
	while (pA < sA && pB >= 0) {
		tmp = seqA[pA] + seqB[pB];
		if (tmp < T) pA++;
		else if (tmp > T) pB--;
		else {
			cntA=1, pA++;
			while (pA < sA && seqA[pA]==seqA[pA-1])
				pA++, cntA++;

			cntB=1, pB--;
			while (pB >= 0 && seqB[pB]==seqB[pB+1])
				pB--, cntB++;

			ret += 1LL*cntA*cntB;
		}
	}
	printf("%lld\n", ret);
	return 0;	
}

/*
// baekjoon 2143 yechan [First Solve using map, 356ms]
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_NN= (MAX_N*(MAX_N+1))/2;
int T, N, M, A[MAX_N], B[MAX_N];
int seqA[MAX_NN];
map<int, int> m;

int main() {
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);

	for (int i=0, k=0; i<N; i++) {
		int sum=0;
		for (int j=i; j<N; j++, k++) {
			sum += A[j];
			seqA[k] = sum;
		}
	}

	scanf("%d", &M);
	for (int i=0; i<M; i++)
		scanf("%d", &B[i]);

	for (int i=0; i<M; i++) {
		int sum=0;
		for (int j=i; j<M; j++) {
			sum += B[j];
			m[sum]++;
		}
	}

	sort(seqA, seqA+(N*(N+1))/2);

	long long ret = 0;
	int maxIdx = N*(N+1)/2;
	for (int i=0; i<maxIdx; i++)
		ret += m[T-seqA[i]];
	printf("%lld\n", ret);
	return 0;	
}
*/