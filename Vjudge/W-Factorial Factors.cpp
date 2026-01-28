// https://vjudge.net/contest/663313#problem/W
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
long long primeFactorization(long long n) {
    long long factors =0;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors++;
            n /= i;
        }
    }
    if (n != 1) {
        factors++;
        n = 1;
    }
    return factors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> s;
    ll MAXI = 1e6+10;
    ll temp =2;
    while(temp<MAXI){
        ll pf = primeFactorization(temp);
        temp++;
        s.push_back(pf);
    }
    //1D prefix sum:

    vector<ll> prefixSum(s.size()+2,0);
    for (int i = 2; i < s.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + s[i-2];
    }
    
    ll n;
    while(cin>>n){
        cout<<prefixSum[n]<<"\n";
    }
    return 0;
}
