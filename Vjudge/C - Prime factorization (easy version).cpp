// Online C++ compiler to run C++ program online
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
//Prime factorization
vector<long long> primeFactorization(long long n) {
    vector<long long> factors;
    for (long long i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        factors.push_back(n);
        n = 1;
    }
    return factors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vector<ll> res = primeFactorization(n);
    for(auto x: res) {
        cout<<x<<" ";
    }
    return 0;
}
