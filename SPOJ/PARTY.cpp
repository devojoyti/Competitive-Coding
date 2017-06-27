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
#define inf 1000000011
#define infll 2000000000000000005LL 
double pi = 3.1415926535897;
 
typedef long long int ll;
typedef long int l;
 
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
 
#define HATERS FUCK_OFF
// ---------------------------------------------------------------------------------//
 
 
int main(){
    int budget, N;
    while(1){
        cin>>budget>>N;
        if(N == 0 && N == budget)
            return 0;
        vector<int> fees(N), fun(N);
        vector<bool> selected(N, 0);
        for(int i=0;i<N;i++)
            cin>>fees[i]>>fun[i];
        vector<int> dp(budget + 1, 0);
        for(int i=0;i<N;i++){
            for(int j=budget;j >= fees[i];j--)
                dp[j] = max(dp[j], dp[j - fees[i]] + fun[i]);
        }
        int ptr = budget;
        for(;ptr > 0;ptr--){
            if(dp[ptr - 1] < dp[ptr])
                break;
        }
        cout<<ptr<<" "<<dp[ptr]<<endl;
    }
    return 0;
} 