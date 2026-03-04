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
vector<vector<int>> res(n+1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unweighted undirected graph
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    visit.assign(n + 1, false);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int hub =0;
    for(int i=1; i<=n; i++){
        if(graph[i].size()==0){
            hub =i;
        }
    }
    res.assign(n+1, vector<int>());
    for(int i=1; i<=n; i++){
        if(i!=hub){
        res[hub].push_back(i);
        res[i].push_back(hub);
        }
    }
    cout<<n-1<<"\n";
    for(int i=1; i<=n; i++){
            if(i!=hub)
            cout<<hub<<" "<<i<<"\n";
    }
    return 0;
}
