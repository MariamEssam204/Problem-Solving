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
ll n,m; cin>>n>>m;
vector<ll > arr(n+1,0);
for(ll i=1;i<=n;i++){
    cin >> arr[i];
}
vector<bool> ans(n+1,1);
while(m--){
    ll a,b; cin>>a>>b;
    if(arr[a]< arr[b]) ans[a]=0;
    else if(arr[a]> arr[b]) ans[b]=0;
    else{
        ans[a]=0;
        ans[b]=0;
    }
}
ll res =0;
for(auto x:ans){
    if(x) res++;
}
cout<<res-1;
return 0;
}
