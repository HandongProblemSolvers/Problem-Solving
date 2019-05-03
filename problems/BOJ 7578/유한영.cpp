#include<cstdio>
#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>
#include<unordered_map>

using namespace std;
int check[500001];

int main() {
	int N;
	long long result = 0;
	cin >> N;
	unordered_map<int, pair<int, int>> factory;
	vector<pair<int, int>> sorted_factory;
	int tmp, loc;
	pair<int, int> tmp_pair;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tmp_pair.first = i;
		factory.insert(make_pair(tmp, tmp_pair));
		check[i] = 0;
	}
	check[N] = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		factory[tmp].second = i;
		tmp_pair = factory[tmp];
		loc = (tmp_pair.first > tmp_pair.second ? tmp_pair.first + 1 : tmp_pair.second + 1);
		check[loc]++;
		sorted_factory.push_back(tmp_pair);
	}
	sort(sorted_factory.begin(), sorted_factory.end());
	for (int i = 1; i < N; i++) {
		check[i] = check[i] + check[i - 1];
		result += (sorted_factory[i].first - check[i]);
	}
	cout << result;
	return 0;
}