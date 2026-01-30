// https://codeforces.com/problemset/problem/236/B
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
vector<ll> cnt_divisors(ll n){
    vector<ll>number_divisors(n+1);
    for(ll i =1;i<=n;i++){
        for(ll j =i;j<=n;j+=i){
            number_divisors[j]++;
        }
    }
    return number_divisors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1073741824;
    ll a,b,c; cin>>a>>b>>c;
    vector<ll> res = cnt_divisors(1e6+1);
    ll sum =0;
    for(ll i =1;i<=a;i++){
        for(ll j =1;j<=b;j++){
            for(ll k =1;k<=c;k++){
                sum += res[i*j*k]%mod;
                sum%mod;
            }
        }
    }
    cout<<sum;
    return 0;
}
