//https://codeforces.com/problemset/problem/1458/A
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
    ll n,m; cin>>n>>m;
    vector<ll> a(n,0);
    vector<ll> b (m,0);
    for(ll i =0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(ll i =1;i<n;i++){
        a[i]-=a[0];
    }
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    ll gcd =0;
    for(ll i =1;i<n;i++){
        gcd = __gcd(gcd,a[i]);
    } 
    ll ans =0;
    for(ll j =0;j<m;j++){
        ans = __gcd(gcd,b[j]+a[0]);
        cout<<abs(ans)<<" ";
    } 
    return 0;
}
