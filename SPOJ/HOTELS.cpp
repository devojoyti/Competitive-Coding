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
 
int main(){
    int N, M;
    cin>>N>>M;
    vector<int> hotels(N);
    for(int i=0;i<N;i++) cin>>hotels[i];
    int sum = 0, i = 0, j = -1;
    int maxval = -inf;
    bool inc = true;
    while(i < N - 1 && inc){
        int ct = 0;
        if(j < N) sum += hotels[++j];
        else ct++;
        if(sum <= M) ct++;
        while(sum > M) sum -= hotels[i++];
        maxval = max(maxval, sum);
        if(ct == 2) inc = false;
    }
    cout<<maxval<<endl;
} 