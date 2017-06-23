#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<string>
#include<cctype>
#include<regex>
 
#define INT_MAX 1000000009
 
#define mod 1000007
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        ll cards = (3*(N*(N + 1))/2 - N)%mod;
        cout<<cards<<endl;
    }
    return 0;
} 