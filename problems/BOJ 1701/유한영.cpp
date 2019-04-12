#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 5001

int main() {
	char cubelang[MAX];
	int h = 0, pos[MAX], rank[MAX],max = -1;
	vector<char> tmp;
	vector<vector<char>> v;
	cin >> cubelang;
	for (int i = strlen(cubelang)-1; i >= 0; i--) {
		tmp.insert(tmp.begin(),cubelang[i]);
		v.push_back(tmp);
	}//vector로 suffix array 구현
	sort(v.begin(), v.end()); //suffix array를 사전순으로 sort

	for (int i = 0; i < v.size(); i++) {
		pos[i] = strlen(cubelang)-(v[i].size()); // 주어진 배열이 몇번째 postfix인지
		rank[strlen(cubelang) - (v[i].size())] = i; // pos의 역함수 rank[pos[i]]=i
	}
	// 
	for (int i = 0; i < strlen(cubelang); i++) {
		if (rank[i] !=0 ) { 
			int j = pos[rank[i] - 1];
			while (cubelang[i + h] == cubelang[j + h])h++; // 접두사 같으면 h++
			if (max < h)max = h;
		}
		if(h > 0)h--;
	}
	cout << max;
	return 0;
}