#include<iostream>
#include<cstdio>
 
typedef long long int lld;
 
int main(){
	while (1){
		double val, num = 0.0;
		scanf("%lf", &val);
		if (val == 0)
			return 0;
		int i;
		for (i = 2; num < val; i++)
			num += double(1) / i;
		printf("%d card(s)\n", i - 2);
	}
} 