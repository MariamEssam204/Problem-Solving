//https://codeforces.com/problemset/problem/1676/E
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
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n; 
        ll q; cin>>q;
        vector<ll> arr(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end(), greater<ll>());
       vector<ll> prefixSum(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
        while(q--){
            ll x; cin>>x;
            auto it = lower_bound(prefixSum.begin()+1,prefixSum.end(),x);
            if(it == prefixSum.end()){
                cout<<-1<<"\n";
            }
            else{
                cout<<it-prefixSum.begin()<<"\n";
            }
            
           
        }
    }
   
    return 0;
}
