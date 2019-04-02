#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int main() {
	int N, L, t, d, min_pos;
	long long *dp, result =0;
	char *dp_td; // t,d,f
	int **rod;//rod[][0]=min_val, rod[][1]=t, rod[][2]=d; 

	cin >> N >> L; // 1<N<100,000 1<L<1,000,000
	
	dp = new long long[N];
	dp_td = new char[N];
	rod = new int*[N];
	for (int i = 0; i < N; i++) {
		cin >> t >> d;
		dp_td[i] = 'f';
		dp[i] = 0;
		rod[i] = new int[3];
		min_pos = t < d ? t : d;
		rod[i][0] = min_pos; rod[i][1] = t; rod[i][2] = d;
		for (int j = i - 1; j >= 0 && i > 0 ; j--) {
			if (rod[j][0] > min_pos){
				rod[j+1][0] = rod[j][0]; rod[j+1][1] = rod[j][1];rod[j+1][2] = rod[j][2];
				rod[j][0] = min_pos; rod[j][1] = t;	rod[j][2] = d;
			}
			else break;
		}
	}
	for(int i=0;i<N;i++)dp[i] = rod[i][1] - rod[i][2] > 0 ? rod[i][1] - rod[i][2] + L : rod[i][2] - rod[i][1] + L;
	for (int i = 0; i < N; i++) {
		long long max_val = dp[i];
		char max_chr = dp_td[i];
		for (int j = i-1; j >= 0; j--) {
			if (rod[i][1] == rod[j][1] && rod[i][2] > rod[j][2] && dp_td[j] != 't') {
				if (dp[i] + dp[j] > dp[i]) {
					max_val = dp[i] + dp[j];
					max_chr = 't';
				}			
			}
			if (rod[i][2] == rod[j][2]&& rod[i][1] > rod[j][1] && dp_td[j] != 'd') {
				if (dp[i] + dp[j] > dp[i]) {
					max_val = dp[i] + dp[j];
					max_chr = 'd';
				}
			}
		}
		dp[i] = max_val;
		dp_td[i] = max_chr;
		if (max_val > result)result = max_val;
	}
	cout << result;
	return 0;
}
