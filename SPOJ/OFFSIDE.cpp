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
    while(1){
        int A, D;
        cin>>A>>D;
        if(A == 0)
            return 0;
        vector<int> attack(A), defend(D);
        for(int i=0;i<A;i++)
            cin>>attack[i];
        for(int i=0;i<D;i++)
            cin>>defend[i];
        sort(attack.begin(), attack.end());
        sort(defend.begin(), defend.end());
        if(attack[0] < defend[1])
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
 
    }
    return 0;
} 