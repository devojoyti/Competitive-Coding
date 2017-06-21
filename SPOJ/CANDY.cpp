#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	while (1){
		int N, sum = 0;
		scanf("%d", &N);
		if (N < 0)
			break;
		vector<int> arr(N);
		for (int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sum /= N;
		int need = 0, give = 0;
		for (int i = 0; i < N; i++){
			if (arr[i] < sum)
				need += sum - arr[i];
			else if (arr[i] > sum)
				give += arr[i] - sum;
		}
		if (need == give)
			printf("%d\n", need);
		else
			printf("-1\n");
	}
} 