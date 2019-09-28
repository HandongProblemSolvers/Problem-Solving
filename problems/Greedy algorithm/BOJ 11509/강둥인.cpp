#include <cstdio>

int main() {
	int N, H;
  int answer = 0;
  int count[1000001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &H);
		if (!count[H+1])
      count[H]++, answer++;

    else
      count[H+1]--, count[H]++;
	}

	printf("%d\n", answer);
	return 0;
}
