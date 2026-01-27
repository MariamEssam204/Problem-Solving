
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
    vector<bool> is_prime = sieve(1e5+100);
    int n; cin >> n;
    if(n==1){
        cout<<1<<"\n"<<1<<"\n";
        return 0;
    }
    else if(n==2){
        cout<<1<<"\n"<<1<<" "<<1<<"\n";
        return 0;
    }
    cout << "2\n";
    for(int i = 2; i <= n+1; i++) {
        if(is_prime[i]) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
    }
    cout << "\n";
    
    return 0;
}
