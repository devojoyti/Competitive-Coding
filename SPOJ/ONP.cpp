#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<unordered_map>
 
using namespace std;
 
#define inp(x) scanf("%d",&x)
#define loop(x, y) for(int i=x;i < y;i++)
 
 
 
 
 
typedef vector<int> vi;
 
int main(){
	int T;
	inp(T);
	unordered_map<char, int> priority;
	priority['('] = 0;
	priority[')'] = 0;
	priority['+'] = 1;
	priority['-'] = 2;
	priority['*'] = 3;
	priority['/'] = 4;
	priority['^'] = 5;
	while (T--){
		int num;
		vector<char> stack;
		vi count;
		string str, ans;
		cin >> str;
		for (int i = 0; i < str.length();i++){
			if (isalpha(str[i]))
				ans = ans + str[i];
			else{
				if (str[i] == '('){
					count.push_back(stack.size());
					stack.push_back(str[i]);
				}
				else if (str[i] == ')'){
					for (int j = stack.size() - 1; j > count.back(); j--){
						ans = ans + stack[j];
						stack.pop_back();
					}
					stack.pop_back();
					count.pop_back();
				}
				else{
					if (stack.empty())
						stack.push_back(str[i]);
					else if (priority[stack.back()] > priority[str[i]]){
						while (priority[stack.back()] > priority[str[i]]){
							ans = ans + stack.back();
							stack.pop_back();
							if (stack.empty())
								break;
						}
					}
					else
						stack.push_back(str[i]);
				}
			}
		}
		while (!stack.empty()){
			if (!(stack.back() == ')') && !(stack.back() == '('))
				ans = ans + stack.back();
			stack.pop_back();
		}
		cout << ans << endl;
	}
	return 0;
} 