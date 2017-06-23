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
    int N, num, xorval = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        xorval ^= num;
    }
    printf("%d\n", xorval);
    return 0;
} 