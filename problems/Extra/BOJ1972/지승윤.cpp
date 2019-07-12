#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    while (s != "*") {
        int len = s.length();
        int i;
        for (i=0; i<len-1; i++) {
            set<string> S;
            for (int j=0; j<len-i-1; j++) {
                string temp = string(1, s[j]) + string(1, s[i+j+1]);
                if (S.find(temp) != S.end()) {
                    cout << s << " is NOT surprising.\n";
                    i = len-1;
                    break;
                }
                else {
                    S.insert(temp);
                }
            }
        }
        if (i != len) cout << s << " is surprising.\n";
        cin >> s;
    }
}
