#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define max 1000011
using namespace std;

char ans[max];
int top;
vector<int> getPi(string &s) {
    int n = s.size();
    int j = 0;
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
    }
    return pi;
}

void kmp(string &s, string &p) {
    int n = s.size();
    int m = p.size();
    int j = 0;
    vector<int> pi = getPi(p);
    vector<int> kmpi(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j])
            j++;
        ans[++top] = s[i];
        kmpi[top] = j;
        if (j == m)
        {
            top -= m;
            j = kmpi[top];
        }
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    kmp(s, t);
    ans[top + 1] = 0;
    cout << (ans + 1) << endl;
}