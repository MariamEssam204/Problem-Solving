// https://codeforces.com/problemset/problem/17/A
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
//prime generation
vector<ll> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    ll count =0;
    ll n,k; cin>>n>>k;
    auto primes = sieve(n);
    for(ll i =2 ; i< primes.size();i++){
        ll temp = primes[i]-1;
        for(ll j = i-1;j>0;j--){
            if(primes[j]+ primes[j-1]==temp){
                count++;
                break;
            }
        }
    }
    if(count>=k){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}
