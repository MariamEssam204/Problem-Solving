#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n,k; cin>>n>>k;
        vector<ll> a(n);
        vector<ll> b(n);
        set<ll> st;
        ll mini = LLONG_MAX;
        ll maxi =0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            mini = min(mini,a[i]);
            maxi = max(maxi,a[i]);
        }   
        ll miss =0;
        ll res=0;
        for(int i=0; i<n; i++){
            cin>>b[i];
            if(b[i]==-1){
                miss++;
            }
        }
        
        if(miss == n){
            res = max(0LL, mini + k - maxi + 1);
            cout<<res<<endl;
        }
        else{
            for(int i=0; i<n; i++){
                if(b[i]!=-1){
                    st.insert(abs(a[i]+b[i]));
                }
            }
            if(st.size() == 1){
                ll x = *st.begin();
            bool valid = true;
            for(int i = 0; i < n; i++){
                if(b[i] == -1){
                    ll val = x - a[i];
                    if(val < 0 || val > k){
                        valid = false;
                        break;
                    }
                }
            }
            cout << (valid ? 1 : 0) << endl;
        }
        else{
            cout<<0<<endl;
        }
        
    }
    }
    return 0;
}
