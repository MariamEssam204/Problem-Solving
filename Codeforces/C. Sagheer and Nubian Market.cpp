// W
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
ll cost1 =0;
bool can(ll mid, vector<ll> & arr,ll s,ll n){
    cost1=0;
    vector<ll> price(n,0);
    for(ll i =0;i<n;i++){
        price[i]=arr[i]+(1+i)*mid;
    }
    sort(price.begin(),price.end());
    for(ll i =0;i<mid;i++){
        cost1+=  price[i];
        if(cost1>s) return false;
    }
    return cost1<=s;
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s;cin>>n>>s;
    vector<ll> arr(n,0);
    for(ll i =0;i<n;i++) cin>>arr[i];
    
    ll l =0, r=n,cost =0, mid, ans;
    while(l<=r){
        mid = l+(r-l)/2;
        if(can(mid,arr,s,n)){ // impelement can()
            ans = mid;
            cost =cost1;
            l = mid+1;
        }
        else{

            r = mid-1;
        }
}

cout<<ans<<" "<<cost;
    return 0;
}
