//https://vjudge.net/contest/661083#problem/P
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;

bool can(ll mid, vector<ll> & x,ll k,ll n){
    vector<ll> res;
    ll sum =0;
    for(ll i =0;i<n;i++){
        sum += x[i];
        if(sum>mid){
             sum -= x[i];
             res. push_back(sum);
             sum =x[i];
        }
        if(sum<=mid && i == n-1){
            res. push_back(sum);
        }
    }
    if(res.size()<=k) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;cin>>n>>k;
    vector<ll> x(n,0);
    ll sum =0;
    for(ll i =0;i<n;i++) {
        cin>>x[i];
        sum += x[i];
    }
    auto max_it = max_element(x.begin(), x.end());
    int max_index = distance(x.begin(), max_it);
    ll l =x[max_index], r=sum,mid, ans;
    while(l<=r){
        mid = l+(r-l)/2;
        if(can(mid,x,k,n)){ // impelement can()
            ans = mid;
            r = mid-1;          
        }
        else{
            l = mid+1;
        }
}

cout<<ans;
    return 0;
}
