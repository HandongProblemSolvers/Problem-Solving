//  Created by Hanyoung Yoo on 13/07/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int optimal_scores[302];
int scores[302];

int get_max_val(int a,int b, int c){
    if(a > b){
        if(b >= c)return a;
        else { // b < c + a > b
            return a > c ? a : c;
        }
    }
    else if(a < b){
        if(a >= c)return b;
        else { // a < c
            return c > b ? c : b ;
        }
    }
    else{ // a == b
        return c > a ? c : a;
    }
}

int get_scores(int level){
    if(optimal_scores[level] != -1)return optimal_scores[level];
    if(level >= 5){
        int level_3,level_4,level_5;
        level_3 = get_scores(level-3) + scores[level-1];
        level_4 = get_scores(level-4) + scores[level-2];
        level_5 = get_scores(level-5) + scores[level-2] + scores[level-3];
        optimal_scores[level] = get_max_val(level_3, level_4, level_5) + scores[level];
    }
    else if(level == 4){
        int level_3,level_4;
        level_3 = get_scores(level-3) + scores[level-1];
        level_4 = get_scores(level-4) + scores[level-2];
        optimal_scores[level] = max(level_3, level_4) + scores[level];
    }
    else if(level == 3){
        int level_3,level_3_2;
        level_3 = get_scores(level-3) + scores[level-1];
        level_3_2 = get_scores(level-3) + scores[level-2];
        optimal_scores[level] = max(level_3, level_3_2) + scores[level];
    }
    else if(level == 2){
        optimal_scores[level] = scores[level-1] + scores[level];
    }
    else optimal_scores[level] = scores[level];
    return optimal_scores[level];
}

int main() {
    int stairs;
    cin>>stairs;
    for(int i=0;i<=stairs;i++)optimal_scores[i] = -1;
    scores[0] = 0;
    optimal_scores[0] = 0;
    for (int i=1;i<=stairs;i++){
        cin>>scores[i];
    }
    cout<<get_scores(stairs)<<endl;
    return 0;
}
