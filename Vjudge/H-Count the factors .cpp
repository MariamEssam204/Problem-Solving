// H-Count the factors 
//https://vjudge.net/contest/585059#problem/H
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
//for prime factorization 
vector<ll> sieve(ll n) {
    vector<ll> divisor(n + 1, 0);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i <= n; i++) {
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
    auto divisor = sieve(1e7);
    while(true){
       ll n; cin>>n;
       if(n==0){
           break;
       }
       auto res = prime_factorization(n, divisor);
       cout<<n<<" : "<<res.size()<<"\n";
   }
    return 0;
}
