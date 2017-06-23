#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<list>
#include<string>
#include<cctype>
#include<regex>
#include<unordered_set>
#include<cmath>
 
#define INT_MAX 1000000009
 
#define mod 1000007
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
ll operate(ll ans, int num, char operand){
    if(operand == '+')
        return (ans + num);
    if(operand == '-')
        return (ans - num);
    if(operand == '*')
        return (ans * num);
    else
        return (ans / num);
}
 
 
int main(){
    int T;
    cin>>T;
    while(T--){
        char opt = '$', ch = '$';
        ll ans = 0;
        while(ch != '='){
            scanf("%c", &ch);
            int ct = 0, num = 0;
            vector<int> store;
            if(ch >= '0' && ch <= '9'){
                while(ch != ' '){
                    store.push_back(ch - '0');
                    scanf("%c", &ch);
                }
                while(!store.empty()){
                    num += store.back()*pow(10, ct++);
                    store.pop_back();
                }
                if(opt == '$')
                    ans = num;
                else
                    ans = operate(ans, num, opt);
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
                opt = ch;
        }
        cout<<ans<<endl;
    }
    return 0;
} 