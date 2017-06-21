#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
 
using namespace std;
 
typedef long long int lld;
 
unordered_map<lld, lld> table;
 
lld exchange(lld N){
	if (!N)
		return 0;
	lld num = table[N];
	if (!num){
		num = max(N, exchange(N / 2) + exchange(N / 3) + exchange(N / 4));
		table[N] = num;
	}
	return num;
}
 
int main(){
	lld N;
	while (scanf("%lld", &N) != EOF)
		printf("%lld\n", exchange(N));
} 