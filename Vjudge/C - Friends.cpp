#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;

vector<vector<int>> graph;
vector<bool> visit;
int DFS(int node, int cnt) { //nose to start transversal
    visit[node] = 1;
   cnt++;
    for (auto v : graph[node]) {
        if (!visit[v]) {
            cnt = DFS(v, cnt);
        }
    }
    return cnt;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// unweighted undirected graph
int t; cin >> t;
while(t--){
int n,m;
cin >> n >> m;
int cnt =0;
graph.assign(n+1, vector<int>());
visit.assign(n + 1, false);
for(int i=0; i<m; i++){
    int u,v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int count = 0; int res =0;
for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
        count++;
        int cont = DFS(i,0);
        res = max(res, cont);
    }
}
cout<<res<<"\n";
}
return 0;
}
