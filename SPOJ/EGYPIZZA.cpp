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
 
int main(){
   int N;
   cin>>N;
   string str;
   vector<int> table(3, 0);
   for(int i=0;i<N;i++){
        cin>>str;
        if(str[0] == '1' && str[2] =='2')
            table[1]++;
        else if(str[0] == '1' && str[2] == '4')
            table[0]++;
        else
            table[2]++;
   }
   int count = 0;
   int temp = min(table[0], table[2]);
   count = temp;
   table[0] -= temp;
   table[2] -= temp;
   count += table[1]/2;
   table[1] = (table[1] & 1 )?1:0;
   count += (table[0] >= 2 && table[1])?1:0;
   if(table[0] >= 2 && table[1]){
        table[0] -= 2;
        table[1] -= 1;
   }
   count += table[0]/4;
   table[0] %= 4;
   count += table[2];
   count += (table[0] <= 2 && table[1])?1:0;
   table[0] -= (table[0] <= 2 && table[1])?table[0]:0;
   count += (table[0] > 0)?1:0;
   cout<<count + 1;
}
 