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
    vector<ll> arr;
    ll diff = 6, hex = 1, ct = 2;
    while(hex < INT_MAX){
        arr.push_back(hex);
        hex += diff;
        diff = 6*ct++;
    }
    while(1){
        ll N;
        cin>>N;
        if(N < 0)
            return 0;
        ll l = 0, r = arr.size() - 1, mid, count = 0;
        while(l <= r){
            mid = l + (r - l)/2;
            if(arr[mid] < N)
                l = mid + 1;
            else if(arr[mid] > N)
                r = mid - 1;
            else
                break;
            count++;
            if(count > 200)
                break;
        }
        if(arr[mid] == N)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
} 