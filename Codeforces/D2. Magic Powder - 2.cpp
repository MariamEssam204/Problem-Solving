//D2. Magic Powder - 2
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
bool can(ll mid, vector<ll> & a,vector<ll> & b,ll &k,ll n){
    ll mini=0; ll sum=0;
    for(ll i =0;i<n;i++){
        if(b[i]<mid*a[i]){
            mini = mid*a[i] - b[i];
            sum+=mini;
            if(sum>k) return false;
            }
        }
    
    
    return sum<=k;
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;cin>>n>>k;
    vector<ll> a(n,0);
    vector<ll> b(n,0);
    for(ll i =0;i<n;i++) cin>>a[i];
    for(ll i =0;i<n;i++) cin>>b[i];

    ll l =0, r=2e9, mid, ans;
    while(l<=r){
        mid = l+(r-l)/2;
        if(can(mid, a,b,k,n)){ // impelement can()
            ans = mid;
            l = mid+1;
        }
        else{

            r = mid-1;
        }
}
cout<<ans;
    return 0;
}
