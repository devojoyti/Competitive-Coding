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
    int T;
    cin>>T;
    while(T--){
        string str1, str2;
        cin>>str1>>str2;
        vector<vector<int>> table(str1.length() + 1, vector<int>(str2.length() + 1, 0));
        for(int i=1;i<=str1.length();i++)
            table[i][0] = i;
        for(int i=1;i<=str2.length();i++)
            table[0][i] = i;
        for(int i=1;i<=str1.length();i++){
            for(int j=1;j<=str2.length();j++){
                if(str1[i - 1] == str2[j - 1])
                    table[i][j] = table[i - 1][j - 1];
                else
                    table[i][j] = min(table[i - 1][j], min(table[i][j - 1], table[i - 1][j - 1])) + 1;
            }
        }
        cout<<table[str1.length()][str2.length()]<<endl;
    }
    return 0;
}  