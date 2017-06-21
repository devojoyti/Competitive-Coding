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
		int a, b;
		scanf("%d %d", &a, &b);
		if (b == 0){
			printf("1\n");
			continue;
		}
		b--;
		vector<int> lastvals;
		lastvals.push_back(a % 10);
		while (a%10 != ((lastvals.back()*a) % 10))
			lastvals.push_back((lastvals.back()*a) % 10);
		b %= lastvals.size();
		printf("%d\n", lastvals[b]);
	}
} 
