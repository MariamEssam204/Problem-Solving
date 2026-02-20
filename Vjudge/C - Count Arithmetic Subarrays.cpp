//https://atcoder.jp/contests/abc369/tasks/abc369_c?lang=en
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
    ll n; cin>>n;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll l=0 , r=0, ans=0;
    while(r < n){
       if(r==l){
        ans++;
       }
       else{
        if(arr[r-1]-arr[r] == arr[l]-arr[l+1]){
            ans+= r-l+1;;
        }
        else{
            l=r-1;
            ans+=2;
        }
       }
       r++;
    }
    cout<<ans<<"\n";
    return 0;
}
