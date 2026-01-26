// F-Prime Frequency
//https://vjudge.net/contest/585059#problem/F
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
//for prime factorization 
vector<ll> sieve(ll n) {
    vector<ll> divisor(n + 1, 0);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i * i <= n; i++) {
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
vector<ll> prime_factorization(ll n, vector<ll>& divisor) {
    vector<ll> res;
    while (n != 1) {
        res.push_back(divisor[n]);
        n /= divisor[n];
    }
    return res;
}

int main() {
    auto divide = sieve(1e6);
    
    ll q;cin>>q;
   while(q--){
       ll n;cin>>n;
       auto res = prime_factorization(n, divide);
       for(auto x:res){
           cout<<x<<" ";
       }
       cout<<"\n";
   }
    return 0;
}
