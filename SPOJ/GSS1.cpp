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
 
#define HATERS FUCK_OFF
// ---------------------------------------------------------------------------------//
 
struct node{
    ll sum, maxsum, prefixsum, suffixsum;
    node(){}
    node(ll sum, ll maxsum, ll prefixsum, ll suffixsum){
        this->sum = sum;
        this->maxsum = maxsum;
        this->prefixsum = prefixsum;
        this->suffixsum = suffixsum;
    }
};
 
 
class segmenttree{
    vector<node> tree;
    int size = 0;
public:
    segmenttree(vector<int> &arr){
        size = arr.size();
        int sz = 2*(1<<(int)ceil(log2(size)));
        tree.resize(sz);
        buildtree(arr, 0, size - 1, 1);
    }
    node merge(node n1, node n2){
        node temp;
        temp.sum = n1.sum + n2.sum;
        temp.maxsum = max(n1.maxsum, max(n2.maxsum, n1.suffixsum + n2.prefixsum));
        temp.prefixsum = max(n1.prefixsum, n1.sum + n2.prefixsum);
        temp.suffixsum = max(n2.suffixsum, n2.sum + n1.suffixsum);
        return temp;
    }
    void buildtree(vector<int> &arr, int l, int r, int pos){
        if(l > r)
            return;
        if(l == r){
            tree[pos].sum = tree[pos].maxsum = tree[pos].prefixsum = tree[pos].suffixsum = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildtree(arr, l, mid, 2*pos);
        buildtree(arr, mid + 1, r, 2*pos + 1);
        tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
    }
    node sumquery(int a, int b, int l, int r, int pos){
        if (l > r || l > b || r < a) 
            return node(-infll, -infll, -infll, -infll);
        if (l >= a && r <= b) 
            return tree[pos];
        int mid = l + (r-l)/2;
        node n1 = sumquery(a, b, l, mid, 2*pos);
        node n2 = sumquery(a, b, mid+1, r, 2*pos + 1);
        if(n1.maxsum == -infll)
            return n2;
        else if(n2.maxsum == -infll)
            return n1;
        return merge(n1, n2);
    }
};
 
 
 
int main(){
    int N;
    scanf("%d", &N);
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);
    segmenttree obj(arr);
    int M;
    scanf("%d", &M);
    while(M--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", obj.sumquery(a - 1, b - 1, 0, N-1, 1).maxsum);
    }
    return 0;
}