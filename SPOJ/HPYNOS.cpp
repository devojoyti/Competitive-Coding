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
#include<unordered_set>
 
#define INT_MAX 1000000009
 
#define mod 1000007
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
inline int squaresum(int num){
    int sum = 0;
    while(num){
        sum += (num%10)*(num%10);
        num/=10;
    }
    return sum;
}
 
int main(){
    int N, ct = 0;
    cin>>N;
    unordered_set<int> store;
    while(1){
        int sum = squaresum(N);
        ct++;
        if(sum == 1){
            cout<<ct<<endl;
            return 0;
        }
        if(store.find(sum) == store.end())
            store.insert(sum);
        else{
            cout<<"-1"<<endl;
            return 0;
        }
        N = sum;
    }
    return 0;
} 