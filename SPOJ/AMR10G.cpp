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
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            cin>>arr[i];
        sort(arr.begin(), arr.end());
        int mindiff = inf;
        for(int i=0;i<N-K + 1;i++)
            mindiff = min(mindiff, arr[K + i - 1] - arr[i]);
        cout<<mindiff<<endl;
    }
    return 0;
} 