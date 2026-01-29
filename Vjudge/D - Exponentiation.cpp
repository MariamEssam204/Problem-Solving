//https://cses.fi/problemset/task/1095
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
ll mod_inverse(ll base,ll n,ll mod){
    ll res=1;
    while(n){
        if(n%2!=0){
            res=(res*base)%mod;
            n--;
        }
        else{
            base=(base*base)%mod;
            n/=2;
        }
    }
    return res; // (base^n)%mod
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        ll a,b; cin>>a>>b;
        ll res= mod_inverse(a,b,1e9+7);
        cout<<res<<"\n";
    }
    return 0;
}
