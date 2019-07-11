#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSurprising(const string& s)
{
    int len = s.length();
    for(int i=1; i<=len-1; i++){
        vector<string> sv;
        for(int j=0; j<len-i; j++){
            string sub(1,s[j]);
            sub += s[j+i];
            for(int k=0; k<sv.size(); k++){
                if(!sv[k].compare(sub)){
                    return false;
                }
            }
            sv.push_back(sub);
        }
    }
    return true;
}

int main(void)
{
    string s;
    while(true) {
        cin >> s;
        if(!s.compare("*")) break;
        cout << s << " is " << (isSurprising(s) ? "surprising" : "NOT surprising") << ".\n";
    }
    return 0;
}