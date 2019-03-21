#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
char ans[1000011];
int top;

int main() {
    string S, T;

    cin >> S >> T;

    int n = S.size();
    int m = T.size();
    int j = 0;

    vector<int> pi(n, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && T[i] != T[j])
          j = pi[j - 1];

        if (T[i] == T[j])
          pi[i] = ++j;
    }

    vector<int> kmp(n, 0);
    for (int i = 0; i < n; i++) {
        while (j > 0 && S[i] != T[j])
          j = pi[j - 1];

        if (S[i] == T[j])
          j++;

        ans[++top] = S[i];

        kmp[top] = j;
        if (j == m) {
            top -= m;
            j = kmpi[top];
        }
    }
    ans[top+1] = 0;

    cout << (ans+1) << endl;
}
