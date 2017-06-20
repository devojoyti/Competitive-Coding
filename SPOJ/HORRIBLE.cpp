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
//#define inf 1000000011
#define infll 2000000000000000005LL 
double pi = 3.1415926535897;
 
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
 
// ---------------------------------------------------------------------------------//
 
ll read(ll id, vector<ll> &tree){
    ll sum = 0;
    while(id > 0){
        sum += tree[id];
        id -= (id & -id);
    }
    return sum;
}
 
void update(ll id, ll val, vector<ll> &tree){
    while(id < tree.size()){
        tree[id] += val;
        id += (id & -id);
    }
}
 
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll N, C, p, q, v, x;
        scanf("%lld %lld", &N, &C);
        vector<ll> tree1(N+1, 0), tree2(N+1, 0);
        for(ll i=0;i<C;i++){
            scanf("%lld", &x);
            if(x){
                scanf("%lld %lld", &p, &q);
                printf("%lld\n", (read(q, tree1)*q) - read(q, tree2) - (read(p - 1, tree1)*(p - 1) - read(p - 1, tree2)));
            }
            else{
                scanf("%lld %lld %lld", &p, &q, &v);
                update(p, v, tree1);
                update(q+1, -v, tree1);
                update(p, v*(p - 1), tree2);
                update(q+1, -v*q, tree2);
            }
        }
    }
    return 0;
} 