//https://codeforces.com/problemset/problem/26/A
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
vector<ll> sieve(ll n) {
    vector<ll> divisor(n + 1, 0);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i <= n; i++) { //if need all prime till n change to i <= n
        if (is_prime[i]) {
            divisor[i] = i;
            if (i <= n / i) {  // Same as i*i <= n
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
                if(divisor[j] == 0){
                    divisor[j] = i;
                    }
                }
             }
        }
    }
    return divisor;
}
set<ll> prime_factorization(ll n, vector<ll>& divisor) {
    set<ll> res;
    while (n != 1) {
        res.insert(divisor[n]);
        n /= divisor[n];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> divisor = sieve(3000+2);
    ll n;cin>> n;
    ll cnt =0;
    ll temp = n;
    while(temp--){
        set<ll> res = prime_factorization(n, divisor);
        if(res.size() == 2) {
            cnt++;
        }
        n--;
    }
    cout<<cnt<<endl;
    return 0;
}
