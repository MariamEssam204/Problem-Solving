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

graph.assign(n+1,vector<int>());
visit.assign(n+1, false);
for(int i=0; i<m; i++){
    int u,v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
if(n==1){
    cout << 0 << "\n";
    return 0;
}
int count = 0;
vector<pair<int, int>> ans;
for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
        count++;
        ans.push_back({i-1, i});
        DFS(i);
    }
}
count--;
cout << count << "\n";
for (int i = 1; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
}
return 0;
}
