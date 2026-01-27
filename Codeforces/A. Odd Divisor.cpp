// https://codeforces.com/problemset/problem/1475/A
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    //tlogn
    while(t--){
        ll n; cin>>n;
        while(n%2==0){
             n/=2;
        }
        if ( n==1) {
            cout<<"No"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}
