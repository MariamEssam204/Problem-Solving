// https://vjudge.net/contest/663313#problem/D
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
//for primality test
vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            if (i <= n / i) {  // Same as i*i <= n
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
                }
            }
        }
    }
    return is_prime;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q; cin>>q;
    vector<bool> is_prime = sieve(1e6+1);
    while(q--){
        ll n;cin>>n;
        if(is_prime[n]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
