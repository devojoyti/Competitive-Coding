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
    int T;
    cin>>T;
    while(T--){
        string str, rev_str;
        cin>>str;
        rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        int N = str.length();
        vector<vector<int>> dp(N+1, vector<int>(N+1));
        for(int i=0;i<N+1;i++)
            dp[i][0] = dp[0][i] = i;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(str[i - 1] == rev_str[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        cout<<dp[N][N]/2<<endl;
    }
    return 0;
} 