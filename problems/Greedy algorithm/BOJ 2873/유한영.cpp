#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int R, C,min_x,min_y;
	int result = 0, min = 1001;
	//ifstream in("input.txt");
	cin >> R >> C;
	if (R % 2 == 1) {
		for (int i = 0; i < R ; i++) {
			for (int j = 0; j < C-1 ; j++) {
				if(i%2==0)cout << 'R';
				else cout << 'L';
			}
			if(i!=R-1)cout << 'D';
		}
	}
	else if (C % 2 == 1) {
		for (int i = 0; i < C ; i++) {
			for (int j = 0; j < R-1; j++) {
				if (i % 2 == 0)cout << 'D';
				else cout << 'U';
			}
			if(i!=C-1)cout << 'R';
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int tmp;
				cin >> tmp;
				if (i % 2 == 0) {
					if (j % 2 == 1) {
						if (min > tmp) {
							min = tmp;
							min_x = i;
							min_y = j;
						}
					}
				}
				else{
					if (j % 2 == 0) {
						if (min > tmp) {
							min = tmp;
							min_x = i;
							min_y = j;
						}

					}
				}
			}
		}
		for (int i = 0; i < (min_x / 2) * 2; i++) {
			for (int j = 0; j < C - 1; j++) {
				cout << (i % 2 == 0 ? 'R' : 'L');
			}
			cout << 'D';
		}
		for (int i = 0; i < min_y; i++) {
			cout << (i % 2 == 0 ? "DR" : "UR");
		}
		for (int i = min_y; i < C - 1; i++) {
			cout << (i % 2 == 0 ? "RD" : "RU");
		}
		R = R - (min_x % 2 == 0 ? min_x + 2 : min_x + 1);
		for (int i = 0; i < R; i++) {
			cout << 'D';
			for (int j = 0; j < C - 1; j++) {
				cout << (i % 2 == 0 ? 'L' : 'R');
			}
		}
	}
	//system("PAUSE");
	return 0;
}
