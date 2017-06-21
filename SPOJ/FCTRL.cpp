#include<iostream>
#include<vector>
 
using namespace std;
 
#define inp(x) scanf("%d",&x)
#define loop(x, y) for(int i=x;i < y;i++)
#define inpl(x) scanf("%lld",&x)
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n", x)
typedef long long int lld;
 
#define size 1000000000
 
int main(){
	int T;
	inp(T);
	while (T--){
		int N, count = 0;
		inp(N);
		for (int i = 5; N / i >= 1; i *= 5)
			count += N / i;
		out(count);
	}
	return 0;
}