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
 
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
 
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
 
struct point{
    int x, y;
    point(){}
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};
 
// ---------------------------------------------------------------------------------//
 
int treat(vector<int> &arr, int x, int y, int day, vector<vector<int>> &table){
    if(x > y)
        return 0;
    if(table[x][y] >= 0)
        return table[x][y];
    table[x][y] =  max(treat(arr, x + 1, y, day + 1, table) + day*arr[x], treat(arr, x, y - 1, day + 1, table) + day*arr[y]);
    return table[x][y];
}
 
 
int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    vector<vector<int>> table(N, vector<int>(N, -1));
    for(int i=0;i<N;i++)
        table[i][i] = arr[i]*N;
    cout<<treat(arr, 0, N-1, 1, table);
    return 0;
} 