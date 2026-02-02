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
   ll n;cin>>n;
   vector<ll> arr(n,0);
   for(int i=0;i<n;i++) cin>>arr[i];
   sort(arr.begin(),arr.end());
   ll q; cin>>q;
   while(q--){
    ll m; cin>>m;
    auto it = upper_bound(arr.begin(), arr.end(),m);
    cout<<it-arr.begin()<<"\n";
   }
    return 0;
}
