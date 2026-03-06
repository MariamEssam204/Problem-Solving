//https://codeforces.com/problemset/problem/893/C
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
vector<ll> cost;
ll DFS(int node) { //nose to start transversal
    visit[node] = 1;
    ll min_cost = cost[node];
    for (auto v : graph[node]) {
        if (!visit[v]) {
            min_cost = min(min_cost, DFS(v));
        }
    }
    return min_cost;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// unweighted undirected graph
 cin >> n >> m;

graph.assign(n+1,vector<int>());
visit.assign(n+1, false);
cost.assign(n+1,0);
for(ll i=1; i<=n; i++){
    cin >> cost[i];
}
for(int i=0; i<m; i++){
    int u,v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
if(m==0){
    ll res=0;
    for(int x : cost){
        res+=x;
    }
    cout << res << "\n";
    return 0;
}
ll ans =0;
for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
        ans += DFS(i);
    }
}
cout << ans << "\n";
return 0;
}
