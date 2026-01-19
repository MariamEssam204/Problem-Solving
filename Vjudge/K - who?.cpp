// https://vjudge.net/contest/659188#problem/K
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n,m;cin>>n>>m;
    vector<vector<char>> arr(n + 1, vector<char>(m + 1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    int q; cin>>q;
    while(q--){
        map<char,int> mp;
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        int mini =0;
        for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            if(arr[i][j]=='a') mp['a']++;
            else if(arr[i][j]=='c') mp['c']++;
            else if(arr[i][j]=='e') mp['e']++;
        }
        
        }
        mini = min(mp['a'],mp['c']);
        mini = min(mini,mp['e']);
        cout<<mini<<"\n";
    }
    return 0;
}
