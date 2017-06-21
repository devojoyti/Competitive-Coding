#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	int N;
	scanf("%d", &N);
	while (N--){
		int num, n1, n2;
		scanf("%d", &num);
		for (int i = 1; i <= num; i++){
			if ((i*(i + 1)) / 2 > num){
				n1 = i - 1;
				n2 = i;
				break;
			}
		}
		int val = num - n1*(n1 + 1) / 2;
		if (val){
			if (n2 & 1)
				printf("TERM %d IS %d/%d\n", num, n2 - val + 1, val);
			else
				printf("TERM %d IS %d/%d\n", num, val, n2 - val + 1);
		}
		else
			printf("TERM %d IS %d/%d\n", num, (n1 & 1) ? 1 : n1, (n1 & 1) ? n1: 1);
	}
	return 0;
} 