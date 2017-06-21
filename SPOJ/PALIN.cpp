#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<unordered_map>
 
using namespace std;
 
#define inp(x) scanf("%d",&x)
#define loop(x, y) for(int i=x;i < y;i++)
#define inpl(x) scanf("%lld",&x)
#define out(x) printf("%d",x)
#define outl(x) printf("%lld\n", x)
typedef long long int lld;
 
bool is_palindrome(vector<int> num){
	bool flag = true;
	for (int i = 0, j = num.size() - 1; i < j; i++, j--){
		if (num[i] != num[j]){
			flag = false;
			break;
		}
	}
	return flag;
}
 
vector<int> make_palindrome(vector<int> &num, int mid, int len){
	int penalty = 0;
	for (int i = len - 1; i >= mid; i--){
		if (num[len - i - 1] == num[i])
			continue;
		else if (num[len - i - 1] > num[i])
			num[i] = num[len - i - 1];
		else{
			num[i] = num[len - i - 1];
			penalty++;
			for (int j = i - 1; j >= 0 && penalty > 0; j--){
				num[j] += penalty;
				if (num[j] >= 10)
					num[j] %= 10;
				else
					penalty--;
			}
			i++;
		}
	}
	return num;
}
 
 
int main(){
	int T;
	inp(T);
	while (T--){
		string str;
		cin >> str;
		vector<int> num;
		for (char ch : str)
			num.push_back(ch - '0');
 
		int len = str.length();
		int mid = (len & 1) ? (len / 2 + 1) : (len / 2);
		if (is_palindrome(num)){
			num[len - 1]++;
			int penalty = 0;
			for (int i = len - 1; i >= 0; i--){
				num[i] += penalty;
				if (num[i] >= 10){
					penalty = num[i] / 10;
					num[i] -= 10;
				}
				else
					penalty = 0;
			}
			if (penalty){
				num.push_back(0);
				for (int i = len; i > 0; i--)
					num[i] = num[i - 1];
				num[0] = penalty;
				len++;
				mid = (len & 1) ? (len / 2 + 1) : (len / 2);
				num = make_palindrome(num, mid, len);
			}
			else
				num = make_palindrome(num, mid, len);
		}
		else
			num = make_palindrome(num, mid, len);
 
		for (int i = 0; i < num.size(); i++)
			out(num[i]);
		printf("\n");
	}
} 