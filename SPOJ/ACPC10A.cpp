#include <iostream>
#include<cstdio>
 
using namespace std;
 
int main() {
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(a == b && b == c && c == 0)
			break;
		else if(b - a == c - b)
			printf("AP %d\n", c + c - b);
		else{
			if(b)printf("GP %d\n", c*(c/b));
			else if(a)printf("GP %d\n", c*((c/a))/2);
		}
	}
	return 0;
} 