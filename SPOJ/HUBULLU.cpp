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
#include<unordered_set>
 
#define INT_MAX 1000000009
 
#define mod 1000007
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
 
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, player;
        cin>>N>>player;
        if(player) 
            cout<<"Pagfloyd wins."<<endl;
        else
            cout<<"Airborne wins."<<endl;
    }
    return 0;
} 