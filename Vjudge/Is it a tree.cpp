#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
//DFS
int n,m; 
vector<vector<int>> graph;
vector<bool> visit;
void DFS(int node) { //nose to start transversal
    visit[node] = 1;
    //cout << node << " ";
    for (auto v : graph[node]) {
        if (!visit[v]) {
            DFS(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unweighted undirected graph
    cin >> n >> m;
    graph.resize(n+1);
    visit.resize(n+1, false);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans =0;
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            ans++;
            DFS(i);
        }
    }
    if(ans==1 && m == n-1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
