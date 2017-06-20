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
 
#define here cout<<endl<<"here"<<endl;
 
typedef long long int ll;
typedef long int l;
typedef long double ld;
 
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
 
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ 23909 ^ h2 ^ 47147;  
    }
};
 
// ---------------------------------------------------------------------------------//
 
int rec(int l, int r, vector<vector<int>> &newcolor, vector<vector<int>> &minsmoke){
    if(l == r) return 0;
    if(r - l == 1){
        if(minsmoke[l][r] < 0){
            minsmoke[l][r] = newcolor[l][l]*newcolor[r][r];
            newcolor[l][r] = (newcolor[l][l] + newcolor[r][r])%100;
        }
        return minsmoke[l][r];
    }
    else{
        if(minsmoke[l][r] >= 0) return minsmoke[l][r];
        int temp = inf;
        for(int i = l;i < r; i++){
            temp = min(temp, rec(l ,i, newcolor, minsmoke) + rec(i + 1, r,  newcolor, minsmoke) + newcolor[l][i]*newcolor[i + 1][r]);
            newcolor[l][r] = (newcolor[l][i] + newcolor[i + 1][r])%100;
        }
        minsmoke[l][r] = temp;
        return temp;
    }
}
 
 
int main(){
    int N;
    while(scanf("%d", &N) > 0){
        vector<int> colors(N);
        for(int i=0;i<N;i++) scanf("%d", &colors[i]);
        vector<vector<int>> newcolor(N, vector<int>(N, -1));
        vector<vector<int>> minsmoke(N, vector<int>(N, -1));
        for(int i=0;i<N;i++) newcolor[i][i] = colors[i];
        printf("%d\n", rec(0, N - 1, newcolor, minsmoke));
    }
    return 0;
} 