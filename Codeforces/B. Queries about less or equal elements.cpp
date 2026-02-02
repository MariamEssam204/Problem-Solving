// https://codeforces.com/problemset/problem/600/B
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
   ll n,m; cin>>n>>m;
   vector<ll> a(n,0);
   vector<ll> b(m,0);
   for(ll i =0;i<n;i++){
    cin>>a[i];
   }
   for(ll i =0;i<m;i++){
    cin>>b[i];
   }
   sort(a.begin(),a.end());
   for(ll i =0;i<m;i++){
    auto it = upper_bound(a.begin(),a.end(),b[i]);
    cout<< it-a.begin()<<" ";
   }
    return 0;
}
