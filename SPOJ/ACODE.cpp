#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
 
using namespace std;
 
int main(){
	string str;
	while (1){
		cin >> str;
		if (str[0] == '0')
			return 0;
		vector<int> arr(str.length() + 1, 0);
		arr[0] = arr[1] = 1;
		for (int i = 2; i < arr.size(); i++){
			if (str[i - 1] != '0')
				arr[i] = arr[i - 1];
			if (((str[i - 2] - '0') * 10 + (str[i - 1] - '0')) < 27 && str[i - 2] != '0')
				arr[i] += arr[i - 2];
		}
		cout << arr.back() << endl;
	}
	return 0;
} 