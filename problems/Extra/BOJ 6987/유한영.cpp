//  Created by Hanyoung Yoo on 26/07/2019.
//  Copyright © 2019 Hanyoung Yoo. All rights reserved.


#include <iostream>

using namespace std;

int draw_matches[6],win_matches[6],loss_matches[6];
bool isavailable;

void draw_validity(int current, int count_draw){
    if(count_draw == 0){
        isavailable = true;
        return;
    }
    if(draw_matches[current] == 0){
        while(draw_matches[current] == 0){
            current ++ ;
        }
    }
    for(int i = current + 1 ; i < 6 ;i ++){
        if(draw_matches[i] != 0){
            draw_matches[current]--;
            draw_matches[i]--;
            count_draw -= 2;
            draw_validity(current, count_draw);
            if(count_draw == 0)return;
            draw_matches[current]++;
            draw_matches[i]++;
            count_draw += 2;
        }
    }
}
int record_matches[6][6];
void win_validity(int current, int count_win,int count_loss){
    
    if(count_win == 0 && count_loss == 0){
        isavailable = true;
        return;
    }
    if(win_matches[current] == 0){
        while(win_matches[current] == 0){
            current++;
        }
    }
    for(int i=0;i<6;i++){
        if(current == i)continue;
        if(record_matches[current][i] == 0 && loss_matches[i] !=0 ){
            record_matches[current][i] = 1;
            record_matches[i][current] = 1;
            loss_matches[i] --;
            win_matches[current]--;
            count_win--;
            count_loss--;
            win_validity(current, count_win, count_loss);
            if(isavailable == true)return;
            record_matches[current][i] = 0;
            record_matches[i][current] = 0;
            loss_matches[i] ++;
            win_matches[current] ++;
            count_win++;
            count_loss++;
            
        }
    }
}

int main() {
    
    for (int i=0;i<4;i++){
        isavailable = true;
        int count_match = 0;
        for(int j=0;j<6;j++){
            cin>>win_matches[j]>>draw_matches[j]>>loss_matches[j];
            if(win_matches[j]+draw_matches[j]+loss_matches[j] > 5){ // 한 팀이 5경기 이상 진행했는 지 체크
                isavailable = false;
            }
            count_match += win_matches[j]+draw_matches[j]+loss_matches[j];
        }
        if (count_match / 2 != 15){ // 경기 수 체크
            isavailable = false;
        }
        if(!isavailable){
            cout<<0<<' ';
            continue;
        }
        int count_draw = 0,count_win = 0,count_loss = 0;
        for(int j=0;j<6;j++){ // 진 경기수, 이긴 경기수, 비긴 경기수 체크
            count_win += win_matches[j];
            count_draw += draw_matches[j];
            count_loss += loss_matches[j];
        }
        
        isavailable = false;
        for(int j=0;j<6;j++){// 무승부 validity 체크
            if(draw_matches[j] != 0){
                draw_validity(j,count_draw);
                break;
            }
        }
        if(!isavailable && count_draw != 0){
            cout<<0<<' ';
            continue;
        }
        isavailable = false;
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                record_matches[j][k] = 0;
            }
        }
        for(int j=0;j<6;j++){// 승/패 validity 체크
            if(win_matches[j] != 0){
                win_validity(j,count_win,count_loss);
                break;
            }
        }
        if(!isavailable && count_win != 0 && count_loss != 0){
            cout<<0<<' ';
            continue;
        }
        cout<<1<<' ';
    }
    return 0;
}
