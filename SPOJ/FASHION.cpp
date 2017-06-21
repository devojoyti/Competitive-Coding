#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		vector<int> men(N), women(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &men[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &women[i]);
		sort(men.begin(), men.end());
		sort(women.begin(), women.end());
		int hotness = 0;
		for (int i = 0; i < N; i++)
			hotness += men[i] * women[i];
		printf("%d\n", hotness);
	}
} 