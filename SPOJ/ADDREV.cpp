#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
 
 
using namespace std;
 
#define INT_MAX 1000000000
 
int rev_int(int num){
	int rev = 0;
	while (num){
		rev *= 10;
		rev += num % 10;
		num /= 10;
	}
	return rev;
}
 
 
int main(){
	int T;
	cin >> T;
	while (T--){
		int n, m;
		cin >> n >> m;
		cout << rev_int(rev_int(n) + rev_int(m)) << endl;
	}
	return 0;
} 