//https://codeforces.com/problemset/problem/893/B
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int, greater<int>> s;
    int n; cin>>n;
    for(int i=2;i<n;i++){
        int x = (pow(2,i)-1)*(pow(2,i-1));
        s.insert(x);
    }
    for(auto it:s){
        if(n%it==0){
            cout<<it<<"\n";
            return 0;
        }
    }
    cout<<1<<"\n";
    return 0;
}
