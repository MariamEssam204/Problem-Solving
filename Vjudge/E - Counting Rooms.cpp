#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;
vector<vector<int>> vis;
vector<vector<char>> graph;
int n, m;
int dx[4] = {0, 1, -1, 0},
    dy[4] = {1, 0, 0, -1};
void DFS_grid(int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int newI, newJ;
        newI = i + dx[k];
        newJ = j + dy[k];
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < m) {
            if (!vis[newI][newJ] && graph[newI][newJ] == '.') {
                DFS_grid(newI, newJ);
            }
        }
    }
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin >> n >> m;
graph.assign(n,vector<char>(m,0));
vis.assign(n, vector<int>(m, 0));

for(int i =0; i<n; i++){
    for(int j=0; j<m; j++){
        cin >> graph[i][j];
    }
}

// cheak connected components
int count = 0;
for(int i =0; i<n; i++){
    for(int j=0; j<m; j++){
    if (!vis[i][j] && graph[i][j] == '.') {
        DFS_grid(i,j);
        count++;
        }
    }
}
cout<<count<<"\n";
return 0;
}
