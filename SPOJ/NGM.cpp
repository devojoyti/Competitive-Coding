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
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
 
int main(){
    int N;
    cin>>N;
    if(N % 10)
        cout<<1<<endl<<N%10<<endl;
    else
        cout<<2<<endl;
    return 0;
}  