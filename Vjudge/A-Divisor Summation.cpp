//A-Divisor Summation
//https://vjudge.net/contest/585059#problem/A
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
ll getDivisors(long long n) {
    ll sum =0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum+=i;
            if (i != n / i && n/i < n) {
                sum+= ( n / i);
            }
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll sum = getDivisors(n);
        
        cout<<sum<<"\n";
    }
    return 0;
}
