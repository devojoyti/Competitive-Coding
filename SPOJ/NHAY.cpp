#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<unordered_map>
#include<algorithm>
#include<set>
 
using namespace std;
 
#define pc(x) putchar(x)
#define gc() getchar()
#define INT_MAX 1000000009
#define inp(x) scanf("%d",&x)
#define loop(x, y) for(int i=x;i < y;i++)
#define inpl(x) scanf("%lld",&x)
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n", x)
typedef long long int lld;
 
inline void fast_inp(int &x)
{
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}
 
inline void fast_out(int n)
{
	register int N = n, rev, count = 0;
	rev = N;
	if (N == 0) { pc('0'); pc('\n'); return; }
	while ((rev % 10) == 0) { count++; rev /= 10; } //obtain the count of the number of 0s
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }  //store reverse of N in rev
	while (rev != 0) { pc(rev % 10 + '0'); rev /= 10; }
	while (count--) pc('0');
	pc('\n');
}
 
void KMP(const string &arr, const string &haystack){
	if (arr.length() > haystack.length())
		return;
	lld N = arr.length();
	vector<int> lps(N, 0);
	for (lld i = 0, j = 1; j < N; j++){
		if (arr[i] == arr[j]){
			lps[j] = lps[j - 1] + 1;
			i++;
		}
		else{
			/*
			while (arr[i] != arr[j] && i != 0)
				i = lps[i];
				*/
			if (arr[i] == arr[j]){
				lps[j] = lps[i] + 1;
				i++;
			}
			else
				lps[j] = 0;
		}
	}
	lld pos = 0, conf = 0, count = 0;
	for (int i = 0; i < haystack.length();i++){
		char ch = haystack[i];
		if (ch == arr[pos]){
			conf++;
			pos++;
		}
		else{
			if (pos > 0)
				conf = pos = lps[pos - 1];
			else
				conf = pos;
			if (ch == arr[pos]){
				conf++;
				pos++;
			}
		}
		if (conf >= N){
			outl(count - pos + 1);
		}
		if (pos > N)
			break;
		count++;
	} 
}
 
int main(){
	lld N;
	bool first = true;
	while (scanf("%lld", &N) == 1){
		if (!first)
			puts("");
		first = false;
		string needle, haystack;
		getline(cin, needle);
		getline(cin, needle);
		getline(cin, haystack);
		KMP(needle, haystack);
	}
	return 0;
} 