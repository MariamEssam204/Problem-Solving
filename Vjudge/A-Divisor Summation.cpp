//A-Divisor Summation
//https://vjudge.net/contest/585059#problem/A
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
set<long long> getDivisors(long long n) {
    set<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            if (i != n / i) {
                divisors.insert(n / i);
            }
        }
    }
    return divisors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        set<ll> divisors = getDivisors(n);
        ll sum = -n;
        for(auto x : divisors){
            sum+= x;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
