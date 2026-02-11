// https://vjudge.net/contest/671167#problem/E
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
    ll n,q; cin>>n>>q;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    vector<ll> prefixXOR (n+1,0);
    for(ll i =1;i<=n;i++){
        prefixXOR[i] =(prefixXOR[i-1]^arr[i-1]);
    }
   while(q--){
      ll l,r; cin>>l>>r; 
      ll ans = prefixXOR[r]^prefixXOR[l-1];
       cout<<ans<<"\n";
    }
    
    return 0;
}
