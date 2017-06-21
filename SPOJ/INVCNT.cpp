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
 
typedef long long int ll;
 
using namespace std;
// ---------------------------------------------------------------------------//
 
int read(int id, vector<int> &tree){
    int sum = 0;
    while(id > 0){
        sum += tree[id];
        id -= (id & -id);
    }
    return sum;
}
 
void update(int id, int val, vector<int> &tree){
    while(id < tree.size()){
        tree[id] += val;
        id += (id & -id);
    }
}
 
struct elem{
    int val, index;
};
 
bool comparator(elem l1, elem l2){
    return l1.val < l2.val;
}
 
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<elem> arr(N);
        vector<int> val(N);
        vector<int> tree(N + 1, 0);
        for(int i=0;i<N;i++){
            cin>>arr[i].val;
            arr[i].index = i;
        }
        sort(arr.begin(), arr.end(), comparator);
        for(int i=0;i<N;i++)
            val[arr[i].index] = i + 1;
        ll inv = 0;
        for(int i=0;i<N;i++){
            update(val[i], 1, tree);
            inv += read(N, tree) - read(val[i], tree);
        }
        cout<<inv<<endl;
    }
    return 0;
}  