//https://atcoder.jp/contests/abc061/submissions/me
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unweighted undirected graph
    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        cout<<graph[i].size()<<"\n";
    }
    return 0;
}
