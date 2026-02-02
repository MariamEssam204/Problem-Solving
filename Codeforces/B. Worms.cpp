//https://codeforces.com/problemset/problem/474/B
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
    ll n; cin>>n; 
    vector<ll> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<ll> prefixSum(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    ll q; cin>>q;
    while(q--){
        ll x; cin>>x;
        auto it = lower_bound(prefixSum.begin()+1,prefixSum.end(),x);
       cout<<it-prefixSum.begin()<<"\n";
        
    }

    return 0;
}
