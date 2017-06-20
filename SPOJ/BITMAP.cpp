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
 
// ---------------------------------------------------------------------------------//
 
 
struct point{
    int x, y;
    point(){}
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};
 
void bfs(vector<vector<bool>> &mat, vector<vector<int>> &dist, point start){
   // vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), 0));
    dist[start.x][start.y] = 0;
    list<point> queue;
    queue.push_back(start);
    while(!queue.empty()){
        point temp = queue.front();
        queue.pop_front();
        // visited[temp.x][temp.y] = 1;
        if(mat[temp.x][temp.y]) 
            dist[temp.x][temp.y] = 0;
        for(int i=0;i<4;i++){
            int xx = dx[i] + temp.x;
            int yy = dy[i] + temp.y;
            if(xx < 0 || xx >= mat.size() || yy < 0 || yy >= mat[0].size())
                continue;
            if(dist[xx][yy] > dist[temp.x][temp.y] + 1){
                queue.push_back(point(xx, yy));
                dist[xx][yy] = dist[temp.x][temp.y] + 1;
            }
        }
    }
}
 
 
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d %d", &N, &M);
        vector<vector<bool>> mat(N, vector<bool>(M, 0));
        char ch[M];
        vector<point> pts;
        for(int i=0;i<N;i++){
            scanf(" %s", ch);
            for(int j=0;j<M;j++){
                if(ch[j] == '1') {
                    mat[i][j] = 1;
                    pts.push_back(point(i, j));
                }
            }
        }
        vector<vector<int>> dist(N, vector<int>(M, inf));
        bfs(mat, dist, pts.back());
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                printf("%d ", dist[i][j]);
            printf("\n");
        }
    }
    return 0;
} 