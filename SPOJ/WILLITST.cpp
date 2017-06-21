#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	lld num;
	cin >> num;
	if (num &(num - 1))
		cout << "NIE" << endl;
	else
		cout << "TAK" << endl;
	return 0;
} 