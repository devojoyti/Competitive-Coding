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
 
int main(){
    while(1){
        int num, N, ct = 1;
        bool flag = 1;
        cin>>N;
        if(!N)
            return 0;
        vector<int> stack;
        list<int> queue;
        for(int i=0;i<N;i++){
            cin>>num;
            queue.push_back(num);
        }
        while(!queue.empty() || !stack.empty()){
            if(!queue.empty() && queue.front() == ct){
                queue.pop_front();
                ct++;
            }
            else{
                if(!stack.empty() && stack.back() == ct){
                    stack.pop_back();
                    ct++;
                }
                else if(!queue.empty()){
                    stack.push_back(queue.front());
                    queue.pop_front();
                }
                else
                    break;
            }
        }
        if(ct == N + 1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
} 