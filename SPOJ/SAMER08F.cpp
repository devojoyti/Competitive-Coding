#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	long long int N;
	while (1){
		scanf("%lld", &N);
		if (!N)
			break;
		printf("%lld\n", (N*(N + 1)*(2 * N + 1)) / 6);
	}
	return 0;
} 