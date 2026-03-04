//https://codeforces.com/problemset/problem/292/B
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;
int n,m;
vector<vector<int>> graph(n+1);
vector<bool> visit(n+1, false);
bool cyclic = false;
void DFS(int node, int parent) {
    visit[node] = 1;
    for (auto v : graph[node]) {
        if (!visit[v]) {
            DFS(v, node);
        }
        else if (v != parent) {
            cyclic = true;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt1 =0, cnt2=0;
    // unweighted undirected graph
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    visit.assign(n + 1, false);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1,-1);
    bool star  =0;
    if(n==1) {cout<<"unknown topology";
        return 0;}
    else{
        for(int i=1; i<graph.size(); i++){
            if(graph[i].size() == n-1){
                star = 1;
                
            }
            else if(graph[i].size()==1){
                cnt1++;
            }
            else if(graph[i].size()==2){
                cnt2++;
            }
            }
        }
        if(cnt1==2 && cnt2 == graph.size()-3){
            cout<<"bus topology";
        }
        else if(cyclic && cnt2==graph.size()-1){
            cout<<"ring topology";
        }
        else if(star && cnt1 == n-1){
            cout<<"star topology";
        }
        else
        cout<<"unknown topology";
    
    return 0;
}
