#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	while (1){
		int N;
		scanf("%d", &N);
		if (!N)
			return 0;
		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		bool flag = 1;
		for (int i = 0; i < N; i++){
			if (arr[i] != i + 1){
				if (arr[arr[i] - 1] != i + 1){
					printf("not ambiguous\n");
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			printf("ambiguous\n");
	}
	return 0;
} 