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
 
typedef long long int ll;
 
 
 
using namespace std;
// ---------------------------------------------------------------------------//
 
int main(){
    int N;
    cin>>N;
    vector<vector<int>> edges(N + 1);
    vector<int> dist(N + 1, 0);
    vector<bool> visited(N + 1, 0);
    int a, b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    list<int> queue;
    queue.push_back(1);
    while(!queue.empty()){
        int temp = queue.front();
        visited[temp] = 1;
        queue.pop_front();
        for(int i=0;i<edges[temp].size();i++){
            if(!visited[edges[temp][i]]){
                dist[edges[temp][i]] = max(dist[edges[temp][i]], 1 + dist[temp]);
                queue.push_back(edges[temp][i]);
            }
        }
    }
    int max_dist = 0, node;
    for(int i=1;i<=N;i++){
        if(max_dist < dist[i]){
            max_dist = dist[i];
            node = i;
        }
        visited[i] = 0;     // refresh lists
        dist[i] = 0;
    }
    queue.push_back(node);
    while(!queue.empty()){
        int temp = queue.front();
        visited[temp] = 1;
        queue.pop_front();
        for(int i=0;i<edges[temp].size();i++){
            if(!visited[edges[temp][i]]){
                dist[edges[temp][i]] = max(dist[edges[temp][i]], 1 + dist[temp]);
                queue.push_back(edges[temp][i]);
            }
        }
    }
    max_dist = 0;
    for(int i=1;i<=N;i++)
        max_dist = max(max_dist, dist[i]);
    cout<<max_dist<<endl;
} 