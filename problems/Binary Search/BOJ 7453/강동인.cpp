#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 4001
using namespace std;

long long AB[MAX_SIZE * MAX_SIZE], CD[MAX_SIZE * MAX_SIZE];
long A[MAX_SIZE];
long B[MAX_SIZE];
long C[MAX_SIZE];
long D[MAX_SIZE];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
          scanf("%ld %ld %ld %ld", &A[i], &B[i], &C[i], &D[i]);

    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[index] = A[i] + B[j];
            CD[index] = C[i] + D[j];
            index++;
        }
    }

    sort(CD, CD + N*N);

    long long count = 0;
    long left = 0, right = N * N;

    for (int i = 0; i < N * N; i++) {
        while (left < right) {
            long long mid = (left + right) / 2;
            if (AB[i] + CD[mid] < 0) left = mid + 1;
            else right = mid;
        }
        long lower_bound = right;
        left = 0, right = N * N;

        while (left < right) {
            long long mid = (left + right) / 2;

            if (AB[i] + CD[mid] <= 0) left = mid + 1;
            else right = mid;
        }
        long upper_bound = right;

        count += upper_bound - lower_bound;
        left = 0, right = N * N;
    }
    printf("%lld\n", count);
    return 0;
}
