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
#include<utility>
 
using namespace std;
 
#define INT_MAX 
 
#define mod 1000000007
#define mod9 1000000009
//#define inf 1000000011
#define infll 2000000000000000005LL 
double pi = 3.1415926535897;
 
typedef long long int ll;
typedef long int l;
typedef long double ld;
 
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
 
template<class T>
inline T gcd(T a, T b){ 
    while (b > 0){
        a %= b; 
        swap(a, b); 
    }
    return a; 
}
 
template<class T>
inline T lcm(T a, T b){
    return a*b / gcd(a, b); 
}
 
inline bool ispalin(string& str){ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++){ 
        if (str[i] != str[n - i - 1]) 
            return false; 
    }
    return true;
}
 
struct point{
    int x, y;
    point(){}
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};
 
// ---------------------------------------------------------------------------------//
 
int main(){
    string str;
    int count = 1;
    while(1){
        getline(cin, str);
        if(str[0] == '-')
            return 0;
        vector<char> stack;
        for(int i=0;i<str.length();i++){
            if(stack.empty()) stack.push_back(str[i]);
            else{
                if(stack.back() == '{' && str[i] == '}') stack.pop_back();
                else stack.push_back(str[i]);
            }
        }
        int p = 0;
        for(int i=1;i<stack.size();i+=2){
            if(stack[i] == stack[i - 1]) p++;
            else p += 2;
        }
        cout<<count++<<". "<<p<<endl;
    }
    return 0;
} 