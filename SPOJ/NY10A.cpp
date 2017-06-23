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
 
#define INT_MAX 1000000009
 
#define mod 1000007
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
inline int bitret(string str){
    int num = 0;
    if(str[0] == 'H')
        num |= 4;
    if(str[1] == 'H')
        num |= 2;
    if(str[2] == 'H')
        num |= 1;
    return num;
}
 
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> arr(8, 0);
        string str, temp;
        cin>>str;
        for(int i=0;i<str.length() - 2;i++){
            temp = str.substr(i, 3);
            arr[bitret(temp)] += 1;
        }
        cout<<N<<" ";
        for(int num: arr)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
} 