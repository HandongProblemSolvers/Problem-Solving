#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int arr[10] = {0};
	for (int i = 0; i < str.size(); ++i)
	{
		arr[str[i] - '0']++;
	}
	if(arr[0]){
		int divsum = 0;
		for (int i = 0; i < 10; ++i)
		{
			divsum += arr[i]*(i%3);
		}
		if(divsum %3 == 0){
			for (int j = 9; j >= 0; --j)
			{
				for (int z = 0; z < arr[j]; ++z)
				{
					cout << j;
				}
			}
		}else{
			cout << -1;
		}
	}else{
		cout << -1;
	}
}