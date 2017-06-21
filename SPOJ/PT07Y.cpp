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
 
int find_head(int node, vector<int> &parent){
    while(parent[node] != node)
        node = parent[node];
    return node;
}
 
void merge_set(int n1, int n2, vector<int> &parent, vector<int> &lumpsize){
    int p1 = find_head(n1, parent);
    int p2 = find_head(n2, parent);
    if(lumpsize[p1] > lumpsize[p2]){
        parent[p2] = p1;
        for(int i=0;i<parent.size();i++){
            if(parent[i] == p2)
                parent[i] = p1;
        }
        lumpsize[p1] += lumpsize[p2];
        lumpsize[p2] = 1;
    }
    else{
        parent[p1] = p2;
        for(int i=1;i<=parent.size();i++){
            if(parent[i] == p1)
                parent[i] = p2;
        }
        lumpsize[p2] += lumpsize[p1];
        lumpsize[p1] = 1;
    }
}
 
 
int main(){
    int N, M;
    cin>>N>>M;
    vector<int> parent(N + 1);
    for(int i=0;i<=N;i++)
        parent[i] = i;
    vector<int> lumpsize(N + 1, 1);
    int a, b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        if(find_head(a, parent) == find_head(b, parent)){
            cout<<"NO"<<endl;
            return 0;
        }
        merge_set(a, b, parent, lumpsize);
    }
    cout<<"YES"<<endl;
    return 0;
} 