#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
       ll n; cin>>n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin>>arr[i];
        ll cnt =0;
        vector<ll> prefixSum(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
        ll maxi =0;
        for(ll i=0; i<n; i++){
            ll last = arr[i];
            maxi = max(maxi, last);
            if(maxi== (prefixSum[i+1]-maxi)) cnt++;
        }
        cout<<cnt<<"\n";
    }
return 0;
}
