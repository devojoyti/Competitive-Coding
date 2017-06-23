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
        int N, M;
        cin>>N>>M;
        vector<vector<int>> floor(N, vector<int>(M)), table(N, vector<int>(M, 0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cin>>floor[i][j];
        }
        table = floor;
        if(N == 1){
            int maxval = 0;
            for(int i=0;i<M;i++)
                maxval = max(maxval, floor[0][i]);
            cout<<maxval<<endl;
            continue;
        }
        if(M == 1){
            int sum = 0;
            for(int i=0;i<N;i++)
                sum += floor[i][0];
            cout<<sum<<endl;
            continue;
 
        }
        for(int i=N-1;i>0;i--){
            for(int j=0;j<M;j++){
                if(j == 0){
                    table[i - 1][0] = max(table[i - 1][0], floor[i - 1][0] + table[i][0]);
                    table[i - 1][1] = max(table[i - 1][1], floor[i - 1][1] + table[i][0]);
                }
                else if(j == M - 1){
                    table[i - 1][M - 1] = max(table[i - 1][M - 1], floor[i - 1][M - 1] + table[i][M - 1]);
                    table[i - 1][M - 2] = max(table[i - 1][M - 2], floor[i - 1][M - 2] + table[i][M - 1]);
                }
                else{
                    table[i - 1][j] = max(table[i - 1][j], floor[i - 1][j] + table[i][j]);
                    table[i - 1][j - 1] = max(table[i - 1][j - 1], floor[i - 1][j - 1] + table[i][j]);
                    table[i - 1][j + 1] = max(table[i - 1][j + 1], floor[i - 1][j + 1] + table[i][j]);
                }
            }
        }
        int maxval = 0;
        for(int i=0;i<M;i++)
            maxval = max(maxval, table[0][i]);
        cout<<maxval<<endl;
    }
    return 0;
} 