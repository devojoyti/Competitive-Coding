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
 
typedef long long int ll;
 
using namespace std;
// ---------------------------------------------------------------------------//
 
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M, num;
        cin>>N>>M;
        int maxn = 0, maxm = 0;
        for(int i=0;i<N;i++){
            cin>>num;
            maxn = max(maxn, num);
        }
        for(int i=0;i<M;i++){
            cin>>num;
            maxm = max(maxm, num);
        }
        if(maxn >= maxm)
            cout<<"Godzilla"<<endl;
        else
            cout<<"MechaGodzilla"<<endl;
    }
    return 0;
} 