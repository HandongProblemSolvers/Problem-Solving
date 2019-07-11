//  Created by Hanyoung Yoo on 11/07/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.

#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int main() {
    string alphabet;
    int cnt_alpha[26][26];
    map<char,int> m;
    char alpha = 'A';
    for(int i=0;i<26;i++){
        m.insert(make_pair(alpha,i));
        alpha = alpha + 1;
    }
    while (true){
        cin>>alphabet;
        if(alphabet.compare("*") == 0 )break;
        int len = (int)alphabet.size();
        int x,y,flag = 0;
        for(int i=1;i<len;i++){
            memset(cnt_alpha,0,sizeof(cnt_alpha));
            for(int j=0;j<len-i;j++){
                x = m.find(alphabet.at(j))->second;
                y = m.find(alphabet.at(j+i))->second;
                if(cnt_alpha[x][y] == 1){
                    cout<< alphabet << " is NOT surprising." <<endl;
                    flag = 1;
                    break;
                }
                else cnt_alpha[x][y]++;
            }
            if(flag == 1)break;
        }
        if(flag == 0)cout<< alphabet << " is surprising." <<endl;
    }
    return 0;
}
